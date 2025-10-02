/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:51:04 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/01 23:03:59 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// Create copy for backtracking
char	**create_copy(t_map *map)
{
	char	**copy;
	int		idx;

	copy = ft_calloc(map->height + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	idx = 0;
	while (idx < map->height)
	{
		copy[idx] = ft_strdup(map->grid[idx]);
		if (!copy[idx])
		{
			while (idx-- > 0)
				free(copy[idx]);
			free(copy);
			return (NULL);
		}
		idx++;
	}
	copy[map->height] = NULL;
	return (copy);
}

// Remove the fourth last lines to disable diagonal
// if needed, not sure it's necessary
int	backtracking(t_map *map, int x, int y, char **visited)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return (-1);
	if (map->grid[y][x] == '.' || map->grid[y][x] == '\0')
		return (-1);
	if (map->grid[y][x] == '1' || visited[y][x])
		return (0);
	visited[y][x] = 1;
	if (backtracking(map, x + 1, y, visited)
		|| backtracking(map, x - 1, y, visited)
		|| backtracking(map, x, y + 1, visited)
		|| backtracking(map, x, y - 1, visited)
		|| backtracking(map, x + 1, y + 1, visited)
		|| backtracking(map, x + 1, y - 1, visited)
		|| backtracking(map, x - 1, y + 1, visited)
		|| backtracking(map, x - 1, y - 1, visited))
		return (-1);
	return (0);
}
