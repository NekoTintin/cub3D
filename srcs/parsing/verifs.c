/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:48:15 by qupollet          #+#    #+#             */
/*   Updated: 2025/08/29 18:17:38 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_map_valid(t_map *map)
{
	// TODO
	return (1);
}

// Check if the file has a .cub extension
int	is_cub_format(const char *filename)
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