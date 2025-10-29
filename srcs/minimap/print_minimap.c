/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:36:06 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/29 18:30:35 by qupollet         ###   ########.fr       */
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
	return ;
}

static void	print_to_minimap(char **map_ref, t_img *img)
{
	int		y;
	int		x;
	int		color;

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
			print_rect(img, x * MINIMAP_TILE_SIZE,
				y * MINIMAP_TILE_SIZE, color);
			x++;
		}
		y++;
	}
}

void	map_to_minimap(t_game *game)
{
	char	**map_rep;

	map_rep = map_to_char(game);
	if (!map_rep)
		return ;
	print_to_minimap(map_rep, game->minimap);
	free_tab(map_rep);
	return ;
}
