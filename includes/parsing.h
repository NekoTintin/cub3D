/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:38:56 by qupollet          #+#    #+#             */
/*   Updated: 2025/08/29 18:17:49 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_map
{
	int		width;
	int		height;
	char	**grid;
}				t_map;

// parsing.c
t_map		*ft_parsing(const char *file);

// utils.c
int			get_map_start_line(char *file);
int			get_map_size(char *file, t_map *map);
int			allocate_map(t_map *map);

// verifs.c
int			is_map_valid(t_map *map);
int			is_cub_format(const char *filename);

# endif