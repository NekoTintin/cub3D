/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:36:58 by qupollet          #+#    #+#             */
/*   Updated: 2025/12/30 16:14:00 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	is_map_valid(t_map *map)
{
	char		**copy;
	char		dir;

	if (map_iter(map, check_valid_char) == -1)
		return (-1);
	if (count_start_char(map) == -1)
		return (-1);
	if (map_iter(map, is_start_pos) == -1)
		return (-1);
	copy = create_copy(map);
	if (!copy)
		return (-1);
	dir = map->grid[map->start_y][map->start_x];
	map->grid[map->start_y][map->start_x] = '0';
	copy[map->start_y][map->start_x] = '0';
	if (backtracking_start(map, map->start_x, map->start_y, copy) == -1)
	{
		ft_print_error("Map is not closed");
		free_tab(copy);
		return (-1);
	}
	free_tab(copy);
	map->grid[map->start_y][map->start_x] = dir;
	return (0);
}

// Check if the file has a .cub extension
static int	is_cub_format(char *filename)
{
	char		*ext;
	int			size;
	int			fd;

	size = ft_strlen(filename);
	if (size < 4)
		return (ft_print_error("Filename too short to be a .cub file"), 0);
	ext = filename + size - 4;
	if (ft_strncmp(ext, ".cub", 4) != 0)
		return (ft_print_error("File is not a .cub file"), 0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_print_error("Failed to open file"), 0);
	close(fd);
	return (1);
}

// Check if map contain all required elements
// NO, SO, WE, EA, F, C
static int	check_file_completed(t_map *map)
{
	if (!map->north)
		return (ft_print_error("Missing texture path: North"), -1);
	else if (!map->south)
		return (ft_print_error("Missing texture path: South"), -1);
	else if (!map->west)
		return (ft_print_error("Missing texture path: West"), -1);
	else if (!map->east)
		return (ft_print_error("Missing texture path: East"), -1);
	else if (map->floor[0] == -1 || map->floor[1] == -1 || map->floor[2] == -1)
		return (ft_print_error("Missing color: Floor"), -1);
	else if (map->ceiling[0] == -1 || map->ceiling[1] == -1
		|| map->ceiling[2] == -1)
		return (ft_print_error("Missing color: Ceiling"), -1);
	return (0);
}

t_game	*ft_parsing(const char *file)
{
	t_game		*game;
	t_map		*map;

	map = init_tmap();
	if (!map)
		return (NULL);
	if (!is_cub_format((char *)file))
		return (free_tmap(map), NULL);
	if (get_map_size((char *)file, map) == -1)
		return (free_tmap(map), NULL);
	if (allocate_map(map) == -1)
		return (free_tmap(map), NULL);
	if (read_map(map, (char *)file) == -1)
		return (free_tmap(map), NULL);
	if (is_map_valid(map) == -1)
		return (free_tmap(map), NULL);
	if (are_paths_valid(map, (char *)file) == -1)
		return (free_tmap(map), NULL);
	if (check_file_completed(map) == -1)
		return (free_tmap(map), NULL);
	game = init_game(map);
	if (!game)
		return (free_tmap(map), NULL);
	return (game);
}
