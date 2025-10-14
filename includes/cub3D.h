/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:38:19 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/14 16:37:58 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define END "\033[0m"

# include "../libft/libft.h"
# include "parsing.h"
# include "display.h"
# include <fcntl.h>
# include "../minilibx/mlx.h"

typedef struct s_position
{
	double	x;
	double	y;
}				t_position;

typedef struct s_game
{
	t_map			*map;
	t_win_data		*data;
	t_position		*player_pos;
}			t_game;

// Remove later
void	print_char_map(char **map);
void	print_map(t_map *map);

// utils.c
void	ft_print_warning(char *msg);
void	ft_print_error(char *msg);
void	free_tab(char **tab);
void	free_tmap(t_map *map);
void	remove_newline(char *str);

#endif