/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:19:03 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/18 19:24:16 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_tab(char **tablo)
{
	int		idx;

	idx = 0;
	while (tablo[idx])
	{
		free(tablo[idx]);
		idx++;
	}
	free(tablo);
}

void	free_tgame(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_tmap(game->map);
	if (game->wdata)
		free_wdata(game->wdata);
	if (game->player)
		free(game->player);
	free(game);
}

void	free_tmap(t_map *map)
{
	if (!map)
		return ;
	if (map->grid)
		free_tab(map->grid);
	free(map->north);
	free(map->south);
	free(map->west);
	free(map->east);
	free(map);
}

void	free_wdata(t_wdata *data)
{
	if (!data)
		return ;
	if (data->win)
	{
		mlx_destroy_window(data->ptr, data->win);
		data->win = NULL;
	}
	if (data->ptr)
	{
		mlx_destroy_display(data->ptr);
		free(data->ptr);
		data->ptr = NULL;
	}
	free(data);
}

void	free_timg(t_img *img, void *mlx_ptr)
{
	if (!img || !mlx_ptr)
		return ;
	if (img->mlx_img)
		mlx_destroy_image(mlx_ptr, img->mlx_img);
	else
		ft_print_error("Cannot free image: img->mlx_img is NULL");
	img->mlx_img = NULL;
	img->addr = NULL;
	free(img);
}
