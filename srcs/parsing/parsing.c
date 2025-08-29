/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:36:58 by qupollet          #+#    #+#             */
/*   Updated: 2025/08/29 18:17:11 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3D.h"

t_map	*ft_parsing(const char *file)
{
	t_map		*map;

	map = create_tmap();
	if (!map)
		return (NULL);
	if (get_map_size(file, map) == -1)
		return (free_tmap(map), NULL);
	if (allocate_map(map) == -1)
		return (free_tmap(map), NULL);
	
}

t_map	*create_tmap(void)
{
	t_map		*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = 0;
	map->height = 0;
	map->grid = NULL;
	return (map);
}

int	read_map(t_map *map, const char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	buffer_iterator(fd, get_map_start_line(file));
	line = get_next_line(fd);
	close(fd);
	return (0);
}