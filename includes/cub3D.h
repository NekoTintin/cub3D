/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:38:19 by qupollet          #+#    #+#             */
/*   Updated: 2025/12/19 17:43:19 by qupollet         ###   ########.fr       */
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
# include <math.h>
# include "game.h"
# include "images.h"
# include "minimap.h"
# include "parsing.h"
# include "rendering.h"

// utils.c
// free_mem.c
void		free_tab(char **tablo);
void		free_tgame(t_game *game);
void		free_tmap(t_map *map);
void		free_wdata(t_wdata *data);
void		free_textures(t_textures *textures, void *ptr);

// printing.c
void		ft_print_warning(char *msg);
void		ft_print_error(char *msg);
void		print_tab(char **tab);
void		print_map(t_map *map);

// random.c
void		remove_newline(char *str);

#endif