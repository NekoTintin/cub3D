/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_paths2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:14:08 by qupollet          #+#    #+#             */
/*   Updated: 2026/01/15 00:33:16 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	count_valid_tokens(char **arr)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (arr[i])
	{
		if (arr[i][0] != '\0')
			count++;
		i++;
	}
	return (count);
}

char	*get_valid_token(char **arr, int token_num)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (arr[i])
	{
		if (arr[i][0] != '\0')
		{
			if (count == token_num)
				return (arr[i]);
			count++;
		}
		i++;
	}
	return (NULL);
}

int	allocate_textures(t_map *map, char **splited)
{
	char		**target;
	char		*path;

	target = NULL;
	if (ft_strncmp(get_valid_token(splited, 0), "NO", 2) == 0)
		target = &map->north;
	else if (ft_strncmp(get_valid_token(splited, 0), "SO", 2) == 0)
		target = &map->south;
	else if (ft_strncmp(get_valid_token(splited, 0), "WE", 2) == 0)
		target = &map->west;
	else if (ft_strncmp(get_valid_token(splited, 0), "EA", 2) == 0)
		target = &map->east;
	else
		return (ft_print_error("Invalid texture type"), -1);
	if (*target != NULL)
		return (ft_print_error("Duplicate texture definition"), -1);
	path = get_valid_token(splited, 1);
	if (!path)
		return (ft_print_error("Missing texture path"), -1);
	*target = ft_strdup(path);
	if (!*target)
		return (
			ft_print_error("Failed to allocate memory for texture path"), -1);
	return (0);
}

int	valid_colors_loop(int *i, char *trimmed)
{
	while (trimmed[*i] && trimmed[*i] != ' ' && trimmed[*i] != '\t')
	{
		if (!ft_isdigit(trimmed[*i]))
			return (0);
		(*i)++;
	}
	return (1);
}
