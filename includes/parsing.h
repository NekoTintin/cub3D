/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:38:56 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/07 09:54:16 by qupollet         ###   ########.fr       */
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
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			floor[3];
	int			ceiling[3];
}				t_map;

typedef int	(*t_map_action)(t_map *map, char *cell, int x, int y);

// backtracking.c
char		**create_copy(t_map *map);
int			backtracking(t_map *map, int x, int y, char **visited);

// gnl.c
char		*gnl(int fd);

// map_read.c
int			read_map(t_map *map, char *file);

// parsing.c
t_map		*ft_parsing(const char *file);

// read_paths.c
int			are_paths_valid(t_map *map, char *file);
int			allocate_textures(t_map *map, char **splited);

// utils.c
int			get_map_start_line(char *file);
int			buffer_iterator(int fd, char *file);
int			get_map_size(char *file, t_map *map);
int			allocate_map(t_map *map);

// verifs_utils.c
int			is_start_pos(t_map *map, char *cell, int x, int y);
int			check_valid_char(t_map *map, char *cell, int x, int y);
int			count_start_char(t_map *map);
int			map_iter(t_map *map, t_map_action action);

#endif