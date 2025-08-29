/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:35:20 by qupollet          #+#    #+#             */
/*   Updated: 2025/08/29 18:14:05 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	is_map_line(char *line)
{
	int		idx;
	int		has_map_char;

	idx = 0;
	has_map_char = 0;
	while (line[idx])
	{
		if (line[idx] != ' ' && line[idx] != '0' && line[idx] != '1'
			&& line[idx] != 'N' && line[idx] != 'S'
			&& line[idx] != 'E' && line[idx] != 'W' && line[idx] != '\n')
			return (0);
		if (line[idx] == '0' || line[idx] == '1' || line[idx] == 'N'
			|| line[idx] == 'S' || line[idx] == 'E' || line[idx] == 'W')
			has_map_char = 1;
		idx++;
	}
	return (has_map_char);
}

// Map are stored at the end of the file
// this function is needed to get the map
int	get_map_start_line(char *file)
{
	int		fd;
	char	*line;
	int		line_counter;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line_counter = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (is_map_line(line))
		{
			free(line);
			close(fd);
			return (line_counter);
		}
		line_counter++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (-1);
}

static void buffer_iterator(int fd, int size)
{
	char	*buf;
	int		idx;

	idx = 0;
	while (idx < size)
	{
		buf = get_next_line(fd);
		if (!buf)
			break ;
		free(buf);
		idx++;
	}
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
	buffer_iterator(fd, get_map_start_line(file));
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

int allocate_map(t_map *map)
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