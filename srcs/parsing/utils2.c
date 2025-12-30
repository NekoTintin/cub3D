/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:00:56 by qupollet          #+#    #+#             */
/*   Updated: 2025/12/30 16:29:14 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_map_line(char *line)
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

int	set_colors(t_map *map, char **colors, char type)
{
	if (type == 'F')
	{
		map->floor[0] = ft_atoi(colors[0]);
		map->floor[1] = ft_atoi(colors[1]);
		map->floor[2] = ft_atoi(colors[2]);
	}
	else if (type == 'C')
	{
		map->ceiling[0] = ft_atoi(colors[0]);
		map->ceiling[1] = ft_atoi(colors[1]);
		map->ceiling[2] = ft_atoi(colors[2]);
	}
	else
		return (-1);
	return (0);
}
