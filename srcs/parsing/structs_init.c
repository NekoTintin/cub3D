/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmondela <jmondela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:11:27 by qupollet          #+#    #+#             */
/*   Updated: 2025/12/20 08:41:30 by jmondela         ###   ########.fr       */
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
	init_tplayer(game->player, game->map);
	return (game);
}

void	init_tplayer(t_player *player, t_map *map)
{
	player->pos_x = map->start_x;
	player->pos_y = map->start_y;
	player->dir_x = 0;
	player->dir_y = -1;
	player->plane_x = 0.66;
	player->plane_y = 0;
	ft_printf("init %d\n",player->plane_x);
}
