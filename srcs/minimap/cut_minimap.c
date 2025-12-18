/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:20:53 by qupollet          #+#    #+#             */
/*   Updated: 2025/12/18 11:38:13 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"a

// Reminder
// MINIMAP_WIDTH = 222
// MINIMAP_HEIGHT = 182
// MINIMAP_TILE_SIZE = 20

static void	fill_map(char ***map, t_game *game, int width, int height)
{
	char		**map_ref;
	int			i;
	int			j;
	int			mx;
	int			my;

	map_ref = *map;
	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			my = game->player->pos_y - (height / 2) + j;
			mx = game->player->pos_x - (width / 2) + i;
			if (my < 0 || mx < 0 || my >= game->map->height
				|| mx >= game->map->width)
				map_ref[j][i] = '.';
			else
				map_ref[j][i] = game->map->grid[my][mx];
			i++;
		}
		j++;
	}
}

static char	**allocate_minimap(int width, int height)
{
	char			**map;
	int				idx;

	map = ft_calloc(height + 1, sizeof(char *));
	if (!map)
		return (NULL);
	idx = 0;
	while (idx < height)
	{
		map[idx] = ft_calloc(width + 1, sizeof(char));
		if (!map[idx])
			return (free_tab(map), NULL);
		idx++;
	}
	return (map);
}

char	**map_to_char(t_game *game)
{
	char	**map_rep;
	int		width;
	int		height;

	width = ((MINIMAP_WIDTH - 2) / MINIMAP_TILE_SIZE) + 2;
	height = ((MINIMAP_HEIGHT - 2) / MINIMAP_TILE_SIZE) + 2;
	map_rep = allocate_minimap(width, height);
	if (!map_rep)
		return (NULL);
	fill_map(&map_rep, game, width, height);
	return (map_rep);
}
