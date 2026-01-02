/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:36:06 by qupollet          #+#    #+#             */
/*   Updated: 2026/01/02 18:20:33 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	print_rect(t_img *img, int x, int y, int color)
{
	t_rect		*rect;

	rect = init_rectangle(x, y, MINIMAP_TILE_SIZE, MINIMAP_TILE_SIZE);
	if (!rect)
		return ;
	put_rectangle_to_img(img, color, rect);
	free(rect);
}

static int	get_base(double offset)
{
	return ((int)floor(-offset * MINIMAP_TILE_SIZE));
}

static void	print_to_minimap(char **map_ref, t_img *img, double offset_x,
			double offset_y)
{
	int			y;
	int			x;
	int			color;

	y = 0;
	while (map_ref[y])
	{
		x = 0;
		while (map_ref[y][x])
		{
			if (map_ref[y][x] == '1')
				color = MINIMAP_WALL_COLOR;
			else if (map_ref[y][x] == '0')
				color = MINIMAP_FLOOR_COLOR;
			else
				color = MINIMAP_EMPTY_COLOR;
			print_rect(img,
				get_base(offset_x) + x * MINIMAP_TILE_SIZE,
				get_base(offset_y) + y * MINIMAP_TILE_SIZE,
				color);
			x++;
		}
		y++;
	}
}

void	map_to_minimap(t_game *game)
{
	char	**map_rep;
	double	offset_x;
	double	offset_y;

	map_rep = map_to_char(game);
	if (!map_rep)
		return ;
	offset_x = game->player->pos_x - floor(game->player->pos_x);
	offset_y = game->player->pos_y - floor(game->player->pos_y);
	print_to_minimap(map_rep, game->minimap, offset_x, offset_y);
	free_tab(map_rep);
}
