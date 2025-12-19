/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:33:32 by qupollet          #+#    #+#             */
/*   Updated: 2025/12/19 16:00:43 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include <stdio.h>

static int	print_player_position(t_img *img, t_player *player)
{
	int			x;
	int			y;
	t_rect		*rect;
	double		offset_x;
	double		offset_y;

	offset_x = player->pos_x - 1 - floor(player->pos_x);
	offset_y = player->pos_y - 1 - floor(player->pos_y);
	x = (int)((((MINIMAP_WIDTH - 2) / MINIMAP_TILE_SIZE) / 2 - offset_x)
			* MINIMAP_TILE_SIZE);
	y = (int)((((MINIMAP_HEIGHT - 2) / MINIMAP_TILE_SIZE) / 2 - offset_y)
			* MINIMAP_TILE_SIZE);
	printf("t_player pos: (%.2f, %.2f)\n", player->pos_x, player->pos_y); //DEBUG
	printf("Player minimap position: (%d, %d)\n", x, y); //DEBUG
	rect = init_rectangle(x, y, MINIMAP_TILE_SIZE, MINIMAP_TILE_SIZE);
	if (!rect)
		return (-1);
	put_rectangle_to_img(img, MINIMAP_PLAYER_COLOR, rect);
	free(rect);
	return (0);
}

static int	draw_border(t_img *img)
{
	int				color;
	int				x;
	int				y;

	color = 0xFFFFFF;
	y = 0;
	while (y < MINIMAP_HEIGHT)
	{
		x = 0;
		while (x < MINIMAP_WIDTH)
		{
			if ((x == 0 || x == 1 || x == MINIMAP_WIDTH - 1
					|| x == MINIMAP_WIDTH - 2) || (y == 0 || y == 1
					|| y == MINIMAP_HEIGHT - 1 || y == MINIMAP_HEIGHT - 2))
				put_pixel_to_img(img, x, y, color);
			x++;
		}
		y++;
	}
	return (0);
}

int	update_mini_map(t_game *game)
{
	int			map_pos_x;
	int			map_pos_y;

	game->minimap = init_new_image(game->wdata->ptr,
			MINIMAP_WIDTH, MINIMAP_HEIGHT);
	if (!game->minimap)
		return (ft_print_error("Failed to create minimap image"), -1);
	map_to_minimap(game);
	print_player_position(game->minimap, game->player);
	draw_border(game->minimap);
	map_pos_x = MINIMAP_MARGIN;
	map_pos_y = WIN_HEIGHT - MINIMAP_HEIGHT - MINIMAP_MARGIN;
	mlx_put_image_to_window(game->wdata->ptr, game->wdata->win,
		game->minimap->mlx_img, map_pos_x, map_pos_y);
	return (0);
}
