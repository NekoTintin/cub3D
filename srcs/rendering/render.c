/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmondela <jmondela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:36:23 by jmondela          #+#    #+#             */
/*   Updated: 2025/12/16 17:40:22 by jmondela         ###   ########.fr       */
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
	// init_texture_pixels(game);
	init_ray(&game->ray);
	raycasting(game->player, game);
	// render_frame(game);
}

void	render(t_game *game)
{
	render_raycast(game);
}
