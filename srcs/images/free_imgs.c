/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:04:25 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/23 21:05:13 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_timg(t_img *img, void *mlx_ptr)
{
	if (!img || !mlx_ptr)
		return ;
	if (img->mlx_img)
		mlx_destroy_image(mlx_ptr, img->mlx_img);
	else
		ft_print_error("Cannot free image: img->mlx_img is NULL");
	img->mlx_img = NULL;
	img->addr = NULL;
	free(img);
}

void	free_rectangle(t_rect *rect)
{
	if (!rect)
		return ;
	free(rect);
}
