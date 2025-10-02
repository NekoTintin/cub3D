/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_paths2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:14:08 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/02 18:21:32 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	allocate_textures(t_map *map, char **splited)
{
	char		**target;

	target = NULL;
	if (ft_strncmp(splited[0], "NO", 2) == 0)
		target = &map->north;
	else if (ft_strncmp(splited[0], "SO", 2) == 0)
		target = &map->south;
	else if (ft_strncmp(splited[0], "WE", 2) == 0)
		target = &map->west;
	else if (ft_strncmp(splited[0], "EA", 2) == 0)
		target = &map->east;
	else
		return (ft_print_error("Invalid texture type"), -1);
	*target = strdup_path(splited[1]);
	if (!*target)
		return (
			ft_print_error("Failed to allocate memory for texture path"), -1);
	return (0);
}
