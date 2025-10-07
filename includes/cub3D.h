/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:38:19 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/07 10:32:24 by qupollet         ###   ########.fr       */
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

// Remove later
void	print_map(t_map *map);

// utils.c
void	ft_print_warning(char *msg);
void	ft_print_error(char *msg);
void	free_tab(char **tab);
void	free_tmap(t_map *map);
void	remove_newline(char *str);

#endif