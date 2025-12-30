/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:35:20 by qupollet          #+#    #+#             */
/*   Updated: 2025/12/30 16:40:23 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// Return: 1 = found start, -1 = error, 0 = continue
static int	process_line(char *line, int *map_started)
{
	if (is_map_line(line) == 1)
	{
		if (!*map_started)
			return (1);
		*map_started = 1;
	}
	else if (*map_started && (line[0] == '\0' || line[0] == '\n'))
		return (ft_print_error("Empty line in map"), -1);
	else if (*map_started)
		return (ft_print_error("Non-map content after map"), -1);
	return (0);
}

// Map are stored at the end of the file
// this function is needed to get the map
int	get_map_start_line(char *file)
{
	int		fd;
	char	*line;
	int		line_counter;
	int		map_started;
	int		result;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line_counter = 0;
	map_started = 0;
	line = gnl(fd);
	while (line)
	{
		remove_newline(line);
		result = process_line(line, &map_started);
		if (result == 1)
			return (free(line), close(fd), line_counter);
		if (result == -1)
			return (free(line), close(fd), -1);
		line_counter++;
		free(line);
		line = gnl(fd);
	}
	return (close(fd), -1);
}

int	buffer_iterator(int fd, char *file)
{
	char	*buf;
	int		idx;
	int		line_num;

	idx = 0;
	line_num = get_map_start_line(file);
	if (line_num == -1)
		return (-1);
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
		return (-1);
	if (buffer_iterator(fd, file) == -1)
		return (close(fd), -1);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > width)
			width = ft_strlen(line);
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->width = width;
	map->height = height;
	return (0);
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
