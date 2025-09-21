/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:38:56 by qupollet          #+#    #+#             */
/*   Updated: 2025/09/22 00:38:46 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct s_map
{
	int			width;
	int			height;
	char		**grid;
	t_position	*start;
}				t_map;

typedef int	(*t_map_action)(t_map *map, char *cell, int x, int y);

// backtracking.c
char		**create_copy(t_map *map);
int			backtracking(t_map *map, int x, int y, char **visited);

// parsing.c
t_map		*ft_parsing(const char *file);

// utils.c
int			get_map_start_line(char *file);
void		buffer_iterator(int fd, int size);
int			get_map_size(char *file, t_map *map);
int			allocate_map(t_map *map);

// verifs_utils.c
int			replace_space(t_map *map, char *cell, int x, int y);
int			is_start_pos(t_map *map, char *cell, int x, int y);
int			check_valid_char(t_map *map, char *cell, int x, int y);
int			count_start_char(t_map *map);
int			map_iter(t_map *map, t_map_action action);

#endif