/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:35:12 by qupollet          #+#    #+#             */
/*   Updated: 2025/09/29 17:08:11 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	normalize_line(int len, char *line)
{
	int		idx;

	idx = 0;
	while (idx < len)
	{
		if (line[idx] == ' ')
			line[idx] = '.';
		if (line[idx] == '\0')
			line[idx] = '.';
		idx++;
	}
	line[len] = '\0';
}

int	allocate_new_line(t_map *map, int idx, int fd)
{
	char		*line;
	char		*new_line;
	int			y;

	line = gnl(fd);
	if (!line)
		return (-1);
	free(map->grid[idx]);
	remove_newline(line);
	new_line = ft_calloc(map->width + 1, sizeof(char));
	if (!new_line)
		return (free(line), -1);
	y = 0;
	while (line[y] && y < map->width)
	{
		new_line[y] = line[y];
		y++;
	}
	normalize_line(map->width, new_line);
	map->grid[idx] = new_line;
	free(line);
	return (0);
}

int	read_map(t_map *map, char *file)
{
	int		fd;
	int		idx;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (buffer_iterator(fd, file) == -1)
		return (close(fd), -1);
	idx = 0;
	while (idx < map->height)
	{
		if (allocate_new_line(map, idx, fd) == -1)
			return (close(fd), gnl(-1), -1);
		idx++;
	}
	gnl(-1);
	close(fd);
	return (0);
}
