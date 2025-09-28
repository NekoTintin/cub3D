/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:36:58 by qupollet          #+#    #+#             */
/*   Updated: 2025/09/28 22:05:17 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	is_map_valid(t_map *map)
{
	char		**copy;

	if (map_iter(map, check_valid_char) == -1)
		return (-1);
	map_iter(map, replace_space);
	if (count_start_char(map) == -1)
		return (-1);
	if (map_iter(map, is_start_pos) == -1)
		return (-1);
	copy = create_copy(map);
	if (!copy)
		return (-1);
	if (backtracking(map, map->start->x, map->start->y, copy) == -1)
	{
		ft_print_error("Map is not closed");
		free_tab(copy);
		return (-1);
	}
	free_tab(copy);
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

static t_map	*create_tmap(void)
{
	t_map		*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = 0;
	map->height = 0;
	map->grid = NULL;
	map->start = ft_calloc(1, sizeof(t_position));
	if (!map->start)
		return (free(map), NULL);
	return (map);
}

static int	read_map(t_map *map, char *file)
{
	int		fd;
	char	*line;
	int		idx;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (buffer_iterator(fd, file) == -1)
		return (close(fd), -1);
	idx = 0;
	while (idx < map->height)
	{
		line = gnl(fd);
		if (!line)
			break ;
		free(map->grid[idx]);
		remove_newline(line);
		map->grid[idx] = line;
		idx++;
	}
	close(fd);
	get_next_line(-1);
	return (0);
}

t_map	*ft_parsing(const char *file)
{
	t_map		*map;

	map = create_tmap();
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
	return (map);
}
