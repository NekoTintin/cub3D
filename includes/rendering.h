#ifndef RENDERING_H
# define RENDERING_H

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
	void			*north_tex;
	void			*south_tex;
	void			*west_tex;
	void			*east_tex;
	int				ceiling_color[3];
	int				floor_color[3];
}					t_textures;

void		render(t_game *game);
void		init_ray(t_ray *ray);
int			raycasting(t_player *player, t_game *game);

// load_textures.c
t_textures	*create_tex_struct(void);
int			load_textures(t_game *game);
void		free_textures(t_textures *textures, void *ptr);

#endif