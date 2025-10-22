/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:38:19 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/23 01:10:03 by qupollet         ###   ########.fr       */
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
# include "game.h"
# include "minimap.h"

// utils.c
// free_mem.c
void				free_tab(char **tablo);
void				free_tgame(t_game *game);
void				free_tmap(t_map *map);
void				free_wdata(t_wdata *data);
void				free_timg(t_img *img, void *mlx_ptr);

// images.c
t_img				*init_new_image(void *mlx_ptr, int w, int h);
void				put_pixel_to_img(t_img *img, int x, int y, int color);

// printing.c
void				ft_print_warning(char *msg);
void				ft_print_error(char *msg);
void				print_tab(char **tab);
void				print_map(t_map *map);

// random.c
void				remove_newline(char *str);

#endif