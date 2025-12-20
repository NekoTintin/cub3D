
#include "../../includes/cub3D.h"

void	draw(t_game *game, t_textures *tex, t_ray *ray, int x)
{
	int			y;
	int			wich_tex;
	int			color;
	int			tex_x;
	int			tex_y;
	double		step;
	double		position;


	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			wich_tex = 0;
		else
			wich_tex = 1;
	}
	else
	{
		if (ray->dir_y > 0)
			wich_tex = 2;
		else
			wich_tex = 3;
	}	
	tex_x = (int)(ray->wall_x * 128);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		tex_x = 128 - tex_x - 1;
	step = 1.0 * 128 / ray->line_height;
	position = (ray->draw_start - game->wdata->win_height / 2
			+ ray->line_height / 2) * step;
	y = ray->draw_start;
	// ft_printf("draw %d\n",y);
	while (y < ray->draw_end)
	{

		tex_y = (int)position & (64 - 1);
		position += step;

		// if (wich_tex == 0)
		color = tex->north_tex->addr[tex_y * tex->north_tex->line_len + tex_x];

		put_pixel_to_img(game->camera, x, y, color);
		// if (tex->index == NORTH || tex->index == EAST)
		// 	color = (color >> 1) & 8355711;
		// if (color > 0)
		// 	game->texture_pixels[y][x] = color;

		
		y++;
	}
}
