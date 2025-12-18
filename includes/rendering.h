#ifndef RENDERING_H
# define RENDERING_H

# include "cub3D.h"

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

void		render(t_game *game);
void		init_ray(t_ray *ray);
int			raycasting(t_player *player, t_game *game);

#endif