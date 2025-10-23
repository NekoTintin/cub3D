/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:27:55 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/23 22:20:56 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

typedef struct s_map_window
{
	void	*ptr;
	void	*win;
	int		width;
	int		height;
	int		tile_size;
}	t_map_window;

int	update_map_render(t_map *map, t_map_window *map_win);

t_map_window	*create_map_window(void)
{
	t_map_window	*map_win;
	int				width;
	int				height;

	width = 800;
	height = 800;
	map_win = ft_calloc(1, sizeof(t_map_window));
	if (!map_win)
		return (NULL);
	map_win->ptr = mlx_init();
	if (!map_win->ptr)
		return (free(map_win), NULL);
	map_win->win = mlx_new_window(map_win->ptr, width, height, "Map");
	if (!map_win->win)
		return (free(map_win->ptr), free(map_win), NULL);
	map_win->width = width;
	map_win->height = height;
	map_win->tile_size = 20;
	return (map_win);
}

int	display_map_window(t_map *map)
{
	t_map_window	*map_win;

	map_win = create_map_window();
	if (!map_win)
		return (ft_print_error("Failed to create map window"), -1);
	update_map_render(map, map_win);
	mlx_loop(map_win->ptr);
	return (0);
}

int	display_map(t_map *map, t_img *img)
{
	int		i;
	int		j;
	t_rect	*rect;

	rect = init_rectangle(0, 0, 20, 20);
	if (!rect)
		return (ft_print_error("Failed to create rectangle"), -1);
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->grid[i][j] == '1')
				put_rectangle_to_img(img, 0x0000FF, rect);
			else if (map->grid[i][j] == '0')
				put_rectangle_to_img(img, 0xFFFFFF, rect);
			else
				put_rectangle_to_img(img, 0x000000, rect);
			rect->start_x += rect->width;
		}
		rect->start_x = 0;
		rect->start_y += rect->height;
	}
	return (0);
}

int	update_map_render(t_map *map, t_map_window *map_win)
{
	t_img		*img;
	t_rect		*rect;

	img = init_new_image(map_win->ptr, map_win->width, map_win->height);
	if (!img)
		return (ft_print_error("Failed to create map image"), -1);
	rect = init_rectangle(100, 100, 50, 50);
	if (!rect)
		return (free_timg(img, map_win->ptr),
			ft_print_error("Failed to create rectangle"), -1);
	display_map(map, img);
	mlx_put_image_to_window(map_win->ptr, map_win->win, img->mlx_img, 0, 0);
	(void)map;
	return (0);
}
