/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:35:20 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/01 23:07:56 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	is_map_line(char *line)
{
	int		idx;
	int		has_map_char;

	idx = 0;
	has_map_char = 0;
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (0);
	if (line[0] == '\n' || line[0] == '\0')
		return (0);
	while (line[idx])
	{
		if (line[idx] != ' ' && line[idx] != '0' && line[idx] != '1'
			&& line[idx] != 'N' && line[idx] != 'S'
			&& line[idx] != 'E' && line[idx] != 'W')
			return (0);
		if (line[idx] == '1' || line[idx] == 'N' || line[idx] == 'S'
			|| line[idx] == 'E' || line[idx] == 'W' || line[idx] == '0')
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
	line = gnl(fd);
	while (line)
	{
		remove_newline(line);
		if (is_map_line(line) == 1)
		{
			free(line);
			close(fd);
			return (line_counter);
		}
		line_counter++;
		free(line);
		line = gnl(fd);
	}
	close(fd);
	return (-1);
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
