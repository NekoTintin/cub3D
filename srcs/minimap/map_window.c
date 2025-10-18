/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:27:55 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/15 17:49:25 by qupollet         ###   ########.fr       */
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

int update_map_render(t_map *map, t_map_window *map_win);

t_map_window	*create_map_window(void)
{
	t_map_window	*map_win;

	map_win = ft_calloc(1, sizeof(t_map_window));
	if (!map_win)
		return (NULL);
	map_win->ptr = mlx_init();
	if (!map_win->ptr)
		return (free(map_win), NULL);
	map_win->win = mlx_new_window(map_win->ptr, 600, 600, "Map");
	if (!map_win->win)
		return (free(map_win->ptr), free(map_win), NULL);
	map_win->width = 600;
	map_win->height = 600;
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

int update_map_render(t_map *map, t_map_window *map_win)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == '1')
			{
				for (int i = 0; i < map_win->tile_size; i++)
					mlx_pixel_put(map_win->ptr, map_win->win,
						x * map_win->tile_size, y * map_win->tile_size, 0x000000FF);
			}
			else if (map->grid[y][x] == '0' || map->grid[y][x] == 'N'
				|| map->grid[y][x] == 'S'
				|| map->grid[y][x] == 'E' || map->grid[y][x] == 'W')
			{
				for (int i = 0; i < map_win->tile_size; i++)
					mlx_pixel_put(map_win->ptr, map_win->win,
						x * map_win->tile_size, y * map_win->tile_size, 0x00FFFFFF);
			}
			x++;
		}
		y++;
	}
	return (0);
}
