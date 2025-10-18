/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:32:46 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/18 19:14:58 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
	new_img->bpp /= 8;
	new_img->width = w;
	new_img->height = h;
	return (new_img);
}

void	put_pixel_to_img(void)
{
	// TODO
	return ;
}