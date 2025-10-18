/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:31:12 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/15 17:22:55 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "cub3D.h"

typedef struct s_game	t_game;

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
	t_textures		*textures;
	int				win_width;
	int				win_height;
	int				tex_size;
}	t_win_data;

// display_window.c
int			display_window(t_game *game);
int			close_window(t_game *game);

// hooks.c
int			key_hook(int keycode, t_game *game);
int			player_move(int keycode, t_win_data *data);

// load_textures.c
t_textures	*create_tex_struct(void);
int			load_textures(t_game *game);
void		free_textures(t_textures *textures, void *ptr);

// utils.c
void		free_win_data(t_win_data *data);

#endif