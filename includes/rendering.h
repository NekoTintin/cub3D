#ifndef RENDERING_H
# define RENDERING_H

# include "cub3D.h"

void		render(t_game *game);
void		init_ray(t_ray *ray);
int			raycasting(t_player *player, t_game *game);


#endif