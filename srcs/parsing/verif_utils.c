/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:42:48 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/15 16:49:05 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_start_pos(t_map *map, char *cell, int x, int y)
{
	if (*cell == 'N' || *cell == 'S' || *cell == 'E' || *cell == 'W')
	{
		map->start_x = x;
		map->start_y = y;
		return (1);
	}
	return (0);
}

int	check_valid_char(t_map *map, char *cell, int x, int y)
{
	(void)map;
	(void)x;
	(void)y;
	if (*cell != '0' && *cell != '1' && *cell != 'N' && *cell != 'S'
		&& *cell != 'E' && *cell != 'W' && *cell != '.' && *cell != '\0')
	{
		ft_printf("Invalid character '%c' at (%d, %d)\n", *cell, x, y);
		ft_print_error("Map contains invalid characters");
		return (-1);
	}
	return (0);
}

int	count_start_char(t_map *map)
{
	int		y;
	int		x;
	int		count;

	if (!map)
		return (-1);
	count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'N' || map->grid[y][x] == 'S'
				|| map->grid[y][x] == 'E' || map->grid[y][x] == 'W')
				count++;
			x++;
		}
		y++;
	}
	if (count > 1 || count == 0)
		return (
			ft_print_error("Map must have exactly one starting position"), -1);
	return (0);
}

int	map_iter(t_map *map, t_map_action act)
{
	int			x;
	int			y;
	int			res;

	if (!map)
		return (-1);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			res = act(map, &map->grid[y][x], x, y);
			if (res != 0)
				return (res);
			x++;
		}
		y++;
	}
	return (0);
}
