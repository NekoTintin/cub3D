/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:31:12 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/14 14:05:08 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "cub3D.h"

typedef struct s_textures
{
	void	*north_tex;
	void	*south_tex;
	void	*west_tex;
	void	*east_tex;
	int		width;
	int		height;
}			t_textures;

// window_data struct
typedef struct s_win_data
{
	void			*ptr;
	void			*win;
	t_map			*map;
	t_textures		*textures;
}	t_win_data;

// display_window.c
int		display_window(t_map *map);
int		close_window(t_win_data *data);

// hooks.c
int		key_hook(int keycode, t_win_data *data);
int		player_move(int keycode, t_win_data *data);

// load_textures.c
t_textures	*create_tex_struct(void);
int			load_textures(t_win_data *data);
void		free_textures(t_textures *textures, void *ptr);

// utils.c
void	free_win_data(t_win_data *data);

#endif