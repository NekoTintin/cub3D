/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:36:23 by jmondela          #+#    #+#             */
/*   Updated: 2025/12/20 16:09:18 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include <stdio.h>

// void	init_texture_pixels(t_game *game)
// {
// 	int	i;

// 	game->texture_pixels = ft_calloc(game->wdata->win_height + 1,
// 			sizeof * game->texture_pixels);
// 	if (!game->texture_pixels)
// 		exit(0);
// 	i = 0;
// 	while (i < game->wdata->win_height)
// 	{
// 		game->texture_pixels[i] = ft_calloc(game->wdata->win_width + 1,
// 				sizeof * game->texture_pixels);
// 		if (!game->texture_pixels[i])
// 			exit(0);
// 		i++;
// 	}
// }

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

static void	render_raycast(t_game *game)
{
	init_ray(&game->ray);
	raycasting(game->player, game);
}

void render_ceiling_floor(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y > WIN_HEIGHT/2)
				put_pixel_to_img(game->camera, x, y, MINIMAP_EMPTY_COLOR);
			else
				put_pixel_to_img(game->camera, x, y, MINIMAP_FLOOR_COLOR);
			x++;
		}
		y++;
	}
}

void	render(t_game *game)
{
	game->camera = init_new_image(game->wdata->ptr,
			WIN_WIDTH, WIN_HEIGHT);
	render_ceiling_floor(game);
	if(!game->camera)
		exit(0);
	render_raycast(game);
	mlx_put_image_to_window(game->wdata->ptr, game->wdata->win,
		game->camera->mlx_img,1,1);

}
