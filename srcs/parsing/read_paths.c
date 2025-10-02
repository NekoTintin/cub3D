/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 23:53:33 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/02 18:22:51 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	is_valid_color(char *color_str)
{
	int		color;

	color = ft_atoi(color_str);
	if (color < 0 || color > 255)
		return (0);
	return (1);
}

static int	check_if_path_is_valid(char *path)
{
	int		fd;

	if (!path || !*path)
		return (ft_print_error("Texture path is NULL or empty"), -1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error("Failed to open texture file");
		ft_printf("Texture path '%s' is not valid\n", path);
		return (-1);
	}
	close(fd);
	return (0);
}

static int	assign_colors(t_map *map, char *line)
{
	char		**colors;
	char		type;

	type = line[0];
	colors = ft_split(line + 2, ',');
	if (!colors || !colors[0] || !colors[1] || !colors[2] || colors[3])
		return (free_tab(colors), ft_print_error("Invalid color line"), -1);
	if (is_valid_color(colors[0]) == 0 || is_valid_color(colors[1]) == 0
		|| is_valid_color(colors[2]) == 0)
		return (free_tab(colors), ft_print_error("Color are not valid"), -1);
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
		return (free_tab(colors), ft_print_error("Invalid color type"), -1);
	return (free_tab(colors), 0);
}

static int	assign_textures(t_map *map, char *line)
{
	char		**path;

	path = ft_split(line, ' ');
	if (!path || !path[0] || !path[1] || path[2])
		return (free_tab(path), ft_print_error("Invalid texture line"), -1);
	if (check_if_path_is_valid(path[1]) == -1)
		return (free_tab(path), -1);
	if (allocate_textures(map, path) == -1)
		return (free_tab(path), -1);
	return (free_tab(path), 0);
}

int	read_from_file(t_map *map, char *map_file)
{
	int			fd;
	char		*line;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (ft_print_error("Failed to open map file"), -1);
	line = gnl(fd);
	while (line)
	{
		remove_newline(line);
		if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
			|| ft_strncmp(line, "WE ", 3) == 0
			|| ft_strncmp(line, "EA ", 3) == 0)
			if (assign_textures(map, line) == -1)
				return (free(line), close(fd), -1);
		else if (ft_strncmp(line, "F ", 2) == 0
			|| ft_strncmp(line, "C ", 2) == 0)
			if (assign_colors(map, line) == -1)
				return (free(line), close(fd), -1);
		free(line);
		line = gnl(fd);
	}
	close(fd);
	return (0);
}
