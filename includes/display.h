/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:31:12 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/07 10:49:41 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "cub3D.h"

// window_data struct
typedef struct s_win_data
{
	void	*ptr;
	void	*win;
	t_map	*map;
}	t_win_data;

// display_window.c
int		display_window(t_map *map);

// utils.c
void	free_win_data(t_win_data *data);

#endif