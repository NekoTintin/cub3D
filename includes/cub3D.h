/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:38:19 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/15 16:58:06 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define END "\033[0m"

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include "parsing.h"
# include "display.h"

// Pos -> player position
// Dir -> player direction vector
// Plane -> camera plane (perpendicular to direction vector)
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_player;

typedef struct s_game
{
	t_map			*map;
	t_win_data		*data;
	t_player		*player;
}			t_game;

// game.c
t_game		*create_game_struct(t_map *map);
int					game_start(t_game *game);

// Remove later
void	print_char_map(char **map);
void	print_map(t_map *map);

// utils.c
void	ft_print_warning(char *msg);
void	ft_print_error(char *msg);
void	free_tab(char **tab);
void	free_tmap(t_map *map);
void	remove_newline(char *str);
void	free_game(t_game *game);

#endif