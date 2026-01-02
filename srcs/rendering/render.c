/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:36:23 by jmondela          #+#    #+#             */
/*   Updated: 2026/01/02 18:26:05 by qupollet         ###   ########.fr       */
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
				put_pixel_to_img(game->camera, x, y,
					game->wdata->textures->floor_color[0] << 16
					| game->wdata->textures->floor_color[1] << 8
					| game->wdata->textures->floor_color[2]);
			else
				put_pixel_to_img(game->camera, x, y,
					game->wdata->textures->ceiling_color[0] << 16
					| game->wdata->textures->ceiling_color[1] << 8
					| game->wdata->textures->ceiling_color[2]);
			x++;
		}
		y++;
	}
}

static void	print_images(t_game *game)
{
	int 		minimap_x;
	int 		minimap_y;

	minimap_x = MINIMAP_MARGIN;
	minimap_y = WIN_HEIGHT - MINIMAP_HEIGHT - MINIMAP_MARGIN;
	mlx_put_image_to_window(game->wdata->ptr, game->wdata->win,
		game->camera->mlx_img, 0, 0);
	mlx_put_image_to_window(game->wdata->ptr, game->wdata->win,
		game->minimap->mlx_img, minimap_x, minimap_y);
}

void	render(t_game *game)
{
	if (game->camera)
		free_timg(game->camera, game->wdata->ptr);
	game->camera = init_new_image(game->wdata->ptr,
			WIN_WIDTH, WIN_HEIGHT);
	if (!game->camera)
		exit(0);
	render_ceiling_floor(game);
	render_raycast(game);
	update_mini_map(game);
	print_images(game);
}
