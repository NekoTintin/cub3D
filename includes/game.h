/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:31:12 by qupollet          #+#    #+#             */
/*   Updated: 2025/12/19 17:51:16 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3D.h"
# include "images.h"

// Window dimensions
# define WIN_WIDTH 1200
# define WIN_HEIGHT 800

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

// Mouse buttons
# define LEFT_CLICK 1
# define MIDDLE_CLICK 2
# define RIGHT_CLICK 3

// Player stats
# define PLAYER_MOVE_SPEED 0.1

typedef struct s_wdata		t_wdata;
typedef struct s_map		t_map;

// Pos -> player position
// Dir -> player direction vector
// Plane -> camera plane (perpendicular to direction vector)
typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}					t_player;

// Base struct, to hold anywhere needed
typedef struct s_game
{
	t_map			*map;
	t_wdata			*wdata;
	t_player		*player;
	t_img			*minimap;
}					t_game;

// To hold textures and colors
typedef struct s_textures
{
	void			*north_tex;
	void			*south_tex;
	void			*west_tex;
	void			*east_tex;
	int				ceiling_color[3];
	int				floor_color[3];
}					t_textures;

// window_data struct
typedef struct s_wdata
{
	void			*ptr;
	void			*win;
	t_textures		*textures;
	int				win_width;
	int				win_height;
	int				tex_size;
}					t_wdata;

// display_window.c
int			display_window(t_game *game);
int			close_window(t_game *game);

// game.c
int			game_start(t_game *game);

// hooks.c
int			key_hook(int keycode, t_game *game);
int			player_move(int keycode, t_game *game);

// load_textures.c
t_textures	*create_tex_struct(void);
int			load_textures(t_game *game);

#endif