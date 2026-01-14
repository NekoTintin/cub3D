/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 23:53:33 by qupollet          #+#    #+#             */
/*   Updated: 2026/01/15 00:32:12 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	is_valid_color(char *color_str)
{
	int		color;
	int		i;
	char	*trimmed;

	if (!color_str || !*color_str)
		return (0);
	trimmed = color_str;
	while (*trimmed == ' ' || *trimmed == '\t')
		trimmed++;
	if (*trimmed == '\0')
		return (0);
	i = 0;
	if (valid_colors_loop(&i, trimmed) == 0)
		return (0);
	if (i == 0)
		return (0);
	while (trimmed[i] == ' ' || trimmed[i] == '\t')
		i++;
	if (trimmed[i] != '\0')
		return (0);
	color = ft_atoi(trimmed);
	if (color < 0 || color > 255)
		return (0);
	return (1);
}

static int	check_if_path_is_valid(char *path)
{
	int		fd;
	int		size;

	if (!path || !*path)
		return (ft_print_error("Texture path is NULL or empty"), -1);
	size = ft_strlen(path);
	if (size < 4)
		return (ft_print_error("Texture path is too short"), -1);
	if (ft_strncmp(path + size - 4, ".xpm", 4) != 0)
		return (ft_print_error("Texture file is not a .xpm file"), -1);
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
	if ((type == 'F' && map->floor[0] != -1)
		|| (type == 'C' && map->ceiling[0] != -1))
		return (ft_print_error("Duplicate color definition"), -1);
	colors = ft_split(line + 2, ',');
	if (!colors || !colors[0] || !colors[1] || !colors[2] || colors[3])
		return (free_tab(colors), ft_print_error("Invalid color line"), -1);
	if (is_valid_color(colors[0]) == 0 || is_valid_color(colors[1]) == 0
		|| is_valid_color(colors[2]) == 0)
		return (free_tab(colors), ft_print_error("Color are not valid"), -1);
	if (set_colors(map, colors, type) == -1)
		return (free_tab(colors), ft_print_error("Invalid color type"), -1);
	return (free_tab(colors), 0);
}

static int	assign_textures(t_map *map, char *line)
{
	char		**path;
	int			count;

	path = ft_split(line, ' ');
	if (!path)
		return (ft_print_error("Invalid texture line"), -1);
	count = count_valid_tokens(path);
	if (count != 2)
		return (free_tab(path), ft_print_error("Invalid texture line"), -1);
	if (check_if_path_is_valid(get_valid_token(path, 1)) == -1)
		return (free_tab(path), -1);
	if (allocate_textures(map, path) == -1)
		return (free_tab(path), -1);
	return (free_tab(path), 0);
}

int	are_paths_valid(t_map *map, char *map_file)
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
		{
			if (assign_textures(map, line) == -1)
				return (gnl(-1), free(line), close(fd), -1);
		}
		else if (ft_strncmp(line, "F ", 2) == 0
			|| ft_strncmp(line, "C ", 2) == 0)
			if (assign_colors(map, line) == -1)
				return (gnl(-1), free(line), close(fd), -1);
		free(line);
		line = gnl(fd);
	}
	return (close(fd), 0);
}
