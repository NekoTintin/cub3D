/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:38:56 by qupollet          #+#    #+#             */
/*   Updated: 2026/01/02 17:53:18 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_game		t_game;
typedef struct s_player		t_player;

typedef struct s_map
{
	int				width;
	int				height;
	char			**grid;
	int				start_x;
	int				start_y;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				floor[3];
	int				ceiling[3];
}				t_map;

typedef int	(*t_map_action)(t_map *map,
		char *cell, int x, int y);

// backtracking.c
int			backtracking_start(t_map *map, int x, int y, char **visited);
char		**create_copy(t_map *map);

// gnl.c
char		*gnl(int fd);

// map_read.c
int			read_map(t_map *map, char *file);

// parsing.c
t_game		*ft_parsing(const char *file);

// read_paths.c and read_paths2.c
int			are_paths_valid(t_map *map, char *file);
int			allocate_textures(t_map *map, char **splited);
int			set_colors(t_map *map, char **colors, char type);

// structs_init.c
t_map		*init_tmap(void);
t_game		*init_game(t_map *map);
int			init_tplayer(t_player *player, t_map *map);

// utils.c and utils2.c
int			get_map_start_line(char *file);
int			buffer_iterator(int fd, char *file);
int			get_map_size(char *file, t_map *map);
int			allocate_map(t_map *map);
int			is_map_line(char *line);

// verifs_utils.c
int			is_start_pos(t_map *map, char *cell, int x, int y);
int			check_valid_char(t_map *map, char *cell, int x, int y);
int			count_start_char(t_map *map);
int			map_iter(t_map *map, t_map_action action);

#endif