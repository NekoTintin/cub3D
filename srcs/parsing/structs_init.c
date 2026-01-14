/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:11:27 by qupollet          #+#    #+#             */
/*   Updated: 2026/01/14 19:14:25 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_map	*init_tmap(void)
{
	t_map		*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = 0;
	map->height = 0;
	map->grid = NULL;
	map->start_x = -1;
	map->start_y = -1;
	map->north = NULL;
	map->south = NULL;
	map->west = NULL;
	map->east = NULL;
	map->floor[0] = -1;
	map->floor[1] = -1;
	map->floor[2] = -1;
	map->ceiling[0] = -1;
	map->ceiling[1] = -1;
	map->ceiling[2] = -1;
	return (map);
}

t_game	*init_game(t_map *map)
{
	t_game		*game;

	if (!map)
		return (NULL);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = map;
	game->wdata = NULL;
	game->player = ft_calloc(1, sizeof(t_player));
	game->minimap = NULL;
	if (!game->player)
		return (free(game), NULL);
	if (init_tplayer(game->player, map) == -1)
		return (free(game->player), free(game), NULL);
	game->map->grid[map->start_y][map->start_x] = '0';
	return (game);
}

int	init_tplayer(t_player *player, t_map *map)
{
	player->move = ft_calloc(1, sizeof(t_movement));
	if (!player->move)
		return (-1);
	player->pos_x = map->start_x + 0.5;
	player->pos_y = map->start_y + 0.5;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	player->start_dir = map->grid[map->start_y][map->start_x];
	return (0);
}
