/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:58:55 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/23 22:38:32 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// NOT DEFINITIVE VERSION
/*
void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	char				*pix;

	if (!img || !img->addr || x < 0
		|| y < 0 || x >= img->width || y >= img->height)
		return ;
	pix = img->addr + (y * img->line_len + x * img->bytes_per_pixel);
}
*/
void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	char				*pix;
	int					i;

	if (!img || !img->addr || x < 0
		|| y < 0 || x >= img->width || y >= img->height)
		return ;
	i = img->bpp - 8;
	pix = img->addr + (y * img->line_len + x * img->bytes_per_pixel);
	while (i >= 0)
	{
		if (img->endian != 0)
			*pix++ = (color >> i) & 0xFF;
		else
			*pix++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	put_rectangle_to_img(t_img *img, int color, t_rect *rect)
{
	int		x;
	int		y;

	if (!img || !rect)
		return ;
	y = rect->start_y;
	while (y < rect->start_y + rect->height)
	{
		x = rect->start_x;
		while (x < rect->start_x + rect->width)
		{
			put_pixel_to_img(img, x, y, color);
			x++;
		}
		y++;
	}
}
