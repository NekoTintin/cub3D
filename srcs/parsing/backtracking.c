/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:51:04 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/18 17:56:56 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	backtracking(t_map *map, int x, int y, char **visited);

// Check if the position (x, y) is valid for backtracking
// Next, check every 0 in the map and backtrack from there
// If any backtrack returns -1, the map is not closed (return 0 otherwise)
int	backtracking_start(t_map *map, int x, int y, char **visited)
{
	int		x_theforgotten;
	int		y_theforbidden;

	if (!map || !visited)
		return (-1);
	if (backtracking(map, x, y, visited) == -1)
		return (-1);
	y_theforbidden = 0;
	x_theforgotten = 0;
	while (y_theforbidden < map->height)
	{
		x_theforgotten = 0;
		while (x_theforgotten < map->width)
		{
			if (visited[y_theforbidden][x_theforgotten] == '0')
			{
				if (backtracking(map, x_theforgotten,
						y_theforbidden, visited) == -1)
					return (-1);
			}
			x_theforgotten++;
		}
		y_theforbidden++;
	}
	return (0);
}

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

// TO REDO
int	backtracking(t_map *map, int x, int y, char **visited)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return (-1);
	if (map->grid[y][x] == '.' || map->grid[y][x] == '\0')
		return (-1);
	if (map->grid[y][x] == '1' || visited[y][x] == 'V')
		return (0);
	visited[y][x] = 'V';
	if (backtracking(map, x + 1, y, visited)
		|| backtracking(map, x - 1, y, visited)
		|| backtracking(map, x, y + 1, visited)
		|| backtracking(map, x, y - 1, visited))
		return (-1);
	return (0);
}
