/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:32:46 by qupollet          #+#    #+#             */
/*   Updated: 2025/12/20 15:37:30 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// REMBERER:
// 0 = little endian
// 1 = big endian
// Also add byte_per_pixel (I don't wanna read the mlx again)
t_img	*init_new_image(void *mlx_ptr, int w, int h)
{
	t_img			*new_img;

	if (!mlx_ptr || w <= 0 || h <= 0)
		return (NULL);
	new_img = malloc(sizeof(t_img));
	if (!new_img)
		return (NULL);
	new_img->mlx_img = mlx_new_image(mlx_ptr, w, h);
	if (!new_img->mlx_img)
		return (free(new_img), NULL);
	new_img->addr = mlx_get_data_addr(new_img->mlx_img,
			&new_img->bpp, &new_img->line_len, &new_img->endian);
	if (!new_img->addr)
	{
		mlx_destroy_image(mlx_ptr, new_img->mlx_img);
		return (free(new_img), NULL);
	}
	new_img->width = w;
	new_img->height = h;
	new_img->bytes_per_pixel = new_img->bpp / 8;
	return (new_img);
}

t_img	*load_from_xpm(char *filename, void *ptr, int *w, int *h)
{
	t_img		*new_img;

	new_img = ft_calloc(1, sizeof(t_img));
	if (!new_img)
		return (NULL);
	new_img->mlx_img = mlx_xpm_file_to_image(ptr, filename, w, h);
	if (!new_img->mlx_img)
		return (free(new_img), NULL);
	new_img->addr = mlx_get_data_addr(new_img->mlx_img,
			&new_img->bpp, &new_img->line_len, &new_img->endian);
	if (!new_img->addr)
	{
		mlx_destroy_image(ptr, new_img->mlx_img);
		return (free(new_img), NULL);
	}
	new_img->width = *w;
	new_img->height = *h;
	new_img->bytes_per_pixel = new_img->bpp / 8;
	return (new_img);
}

t_rect	*init_rectangle(int start_x, int start_y, int width, int height)
{
	t_rect		*rect;

	rect = ft_calloc(1, sizeof(t_rect));
	if (!rect)
		return (NULL);
	rect->start_x = start_x;
	rect->start_y = start_y;
	rect->width = width;
	rect->height = height;
	return (rect);
}
