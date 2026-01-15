/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:35:20 by qupollet          #+#    #+#             */
/*   Updated: 2026/01/15 12:02:58 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// Return: 1 = found start, -1 = error, 0 = continue
static int	process_line(char *line, int *map_started)
{
	if (is_map_line(line) == 1)
	{
		if (!*map_started)
			*map_started = 1;
		return (1);
	}
	return (0);
}

// Map are stored at the end of the file
// this function is needed to get the map
int	get_map_start_line(int fd)
{
	char	*line;
	int		line_counter;
	int		map_started;
	int		start_line;
	int		result;

	get_start_line_init(&line_counter, &map_started, &start_line);
	line = gnl(fd);
	while (line)
	{
		remove_newline(line);
		result = process_line(line, &map_started);
		if (result == 1 && start_line == -1)
			start_line = line_counter;
		if (result == -1)
			return (free(line), -1);
		line_counter++;
		free(line);
		line = gnl(fd);
	}
	if (start_line != -1)
		return (start_line);
	return (-1);
}

int	buffer_iterator(int fd, char *file)
{
	int		fd2;
	char	*buf;
	int		idx;
	int		line_num;

	idx = 0;
	fd2 = open(file, O_RDONLY);
	if (fd2 == -1)
		return (ft_print_error("Failed to open file"), -1);
	line_num = get_map_start_line(fd2);
	close(fd2);
	gnl(-1);
	if (line_num == -1)
		return (ft_print_error("Failed to get map start line"), -1);
	while (idx < line_num)
	{
		buf = gnl(fd);
		if (!buf)
			break ;
		free(buf);
		idx++;
	}
	return (0);
}

// Get map size to allocate memory
int	get_map_size(char *file, t_map *map)
{
	int			fd;
	char		*line;
	int			width;
	int			height;

	width = 0;
	height = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_print_error("Failed to open file"), -1);
	if (buffer_iterator(fd, file) == -1)
		return (close(fd), gnl(-1), -1);
	line = gnl(fd);
	while (line)
	{
		remove_newline(line);
		if (ft_strlen(line) > width)
			width = ft_strlen(line);
		height++;
		free(line);
		line = gnl(fd);
	}
	map->width = width;
	map->height = height;
	return (close(fd), gnl(-1), 0);
}

int	allocate_map(t_map *map)
{
	int		idx;

	map->grid = ft_calloc(map->height + 1, sizeof(char *));
	if (!map->grid)
		return (-1);
	idx = 0;
	while (idx < map->height)
	{
		map->grid[idx] = ft_calloc(map->width + 1, sizeof(char));
		if (!map->grid[idx])
			return (-1);
		idx++;
	}
	return (0);
}
