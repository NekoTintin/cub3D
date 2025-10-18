/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:31:12 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/18 17:58:23 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3D.h"

// Keycodes
# define KEY_ESC 65307

// Moving keys
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_Z 122
# define KEY_Q 113

typedef struct s_wdata t_wdata;

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
	t_wdata			*wdata;
	t_player		*player;
}			t_game;

typedef struct s_textures
{
	void	*north_tex;
	void	*south_tex;
	void	*west_tex;
	void	*east_tex;
	int		ceiling_color;
	int		floor_color;
}			t_textures;

// window_data struct
typedef struct s_wdata
{
	void			*ptr;
	void			*win;
	t_textures		*textures;
	int				win_width;
	int				win_height;
	int				tex_size;
}	t_wdata;

// display_window.c
int			display_window(t_game *game);
int			close_window(t_game *game);

// game.c
int			game_start(t_game *game);

// hooks.c
int			key_hook(int keycode, t_game *game);
int			player_move(int keycode, t_wdata *data);

// load_textures.c
t_textures	*create_tex_struct(void);
int			load_textures(t_game *game);
void		free_textures(t_textures *textures, void *ptr);

#endif