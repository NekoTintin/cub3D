/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmondela <jmondela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:25:33 by jmondela          #+#    #+#             */
/*   Updated: 2026/01/14 15:18:02 by jmondela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	select_texture(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (ray->dir_y > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
}

int	get_clr(int tex_dir, t_textures *tex, int tex_x, int tex_y)
{
	unsigned int	color;

	if (tex_dir == NORTH)
		color = ((unsigned int *)tex->north_tex->addr)
		[tex_y * tex->north_tex->line_len / 4 + tex_x];
	else if (tex_dir == SOUTH)
		color = ((unsigned int *)tex->south_tex->addr)
		[tex_y * tex->south_tex->line_len / 4 + tex_x];
	else if (tex_dir == WEST)
		color = ((unsigned int *)tex->west_tex->addr)
		[tex_y * tex->west_tex->line_len / 4 + tex_x];
	else
		color = ((unsigned int *)tex->east_tex->addr)
		[tex_y * tex->east_tex->line_len / 4 + tex_x];
	return (color);
}

void	draw(t_game *game, t_textures *tex, t_ray *ray, int x)
{
	int				y;
	int				dir;
	int				tex_x;
	double			step;
	double			position;

	dir = select_texture(ray);
	tex_x = (int)(ray->wall_x * TEXTURE_SIZE);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		tex_x = TEXTURE_SIZE - tex_x - 1;
	step = 1.0 * TEXTURE_SIZE / ray->line_height;
	position = (ray->draw_start - game->wdata->win_height / 2
			+ ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		put_pixel_to_img(game->camera, x, y,
			get_clr(dir, tex, tex_x, (int)position & (128 - 1)));
		position += step;
		y++;
	}
}

// void	draw(t_game *game, t_textures *tex, t_ray *ray, int x)
// {
// 	int				y;
// 	int				tex_dir;
// 	unsigned int	color;
// 	int				tex_x;
// 	int				tex_y;
// 	double			step;
// 	double			position;

// 	tex_dir = select_texture(ray);
// 	tex_x = (int)(ray->wall_x * TEXTURE_SIZE);
// 	if ((ray->side == 0 && ray->dir_x < 0)
// 		|| (ray->side == 1 && ray->dir_y > 0))
// 		tex_x = TEXTURE_SIZE - tex_x - 1;
// 	step = 1.0 * TEXTURE_SIZE / ray->line_height;
// 	position = (ray->draw_start - game->wdata->win_height / 2
// 			+ ray->line_height / 2) * step;
// 	y = ray->draw_start;
// 	while (y < ray->draw_end)
// 	{
// 		tex_y = (int)position & (128 - 1);
// 		position += step;
// 		if (tex_dir == NORTH)
// 			color = ((unsigned int *)tex->north_tex->addr)[tex_y * 
//tex->north_tex->line_len / 4 + tex_x];
// 		else if (tex_dir == SOUTH)
// 			color = ((unsigned int *)tex->south_tex->addr)[tex_y * 
//tex->south_tex->line_len / 4 + tex_x];
// 		else if (tex_dir == WEST)
// 			color = ((unsigned int *)tex->west_tex->addr)[tex_y *
// tex->west_tex->line_len / 4 + tex_x];
// 		else
// 			color = ((unsigned int *)tex->east_tex->addr)[tex_y *
// tex->east_tex->line_len / 4 + tex_x];
// 		put_pixel_to_img(game->camera, x, y, color);
// 		y++;
// 	}
// }
