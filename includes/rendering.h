/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmondela <jmondela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:45:58 by qupollet          #+#    #+#             */
/*   Updated: 2026/01/14 16:35:47 by jmondela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# define TEXTURE_SIZE 128

// Textures direction indexes
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

# include "cub3D.h"

typedef struct s_game		t_game;
typedef struct s_player		t_player;

// Raycasting struct
typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}				t_ray;

// To hold textures and colors
typedef struct s_textures
{
	t_img		*north_tex;
	t_img		*south_tex;
	t_img		*west_tex;
	t_img		*east_tex;
	int			ceiling_color[3];
	int			floor_color[3];
}				t_textures;

void		setup_dda(t_ray *ray, t_player *player);
void		perform_dda(t_game *game, t_ray *ray);

void		render(t_game *game);
void		init_ray(t_ray *ray);
int			raycasting(t_player *player, t_game *game);
void		draw(t_game *game, t_textures *tex, t_ray *ray, int x);

// load_textures.c
t_textures	*create_tex_struct(void);
int			load_textures(t_game *game);
void		free_textures(t_textures *textures, void *ptr);

#endif