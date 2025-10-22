/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:32:46 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/23 01:28:30 by qupollet         ###   ########.fr       */
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

// NOT DEFINITIVE VERSION
// A version with endianess handling will be made later
void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	char		*pix;

	if (!img || !img->addr || x < 0
		|| y < 0 || x >= img->width || y >= img->height)
		return ;
	pix = img->addr + (y * img->line_len + x * img->bytes_per_pixel);
	*(int *)pix = color;
}
