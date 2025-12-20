/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:19:03 by qupollet          #+#    #+#             */
/*   Updated: 2025/12/20 16:08:23 by qupollet         ###   ########.fr       */
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
	if (game->camera)
		free_timg(game->camera, game->wdata->ptr);
	if (game->minimap)
		free_timg(game->minimap, game->wdata->ptr);
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
	free_textures(data->textures, data->ptr);
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

void	free_textures(t_textures *textures, void *ptr)
{
	if (!textures)
		return ;
	if (textures->north_tex)
	{
		free_timg(textures->north_tex, ptr);
		textures->north_tex = NULL;
	}
	if (textures->south_tex)
	{
		free_timg(textures->south_tex, ptr);
		textures->south_tex = NULL;
	}
	if (textures->west_tex)
	{
		free_timg(textures->west_tex, ptr);
		textures->west_tex = NULL;
	}
	if (textures->east_tex)
	{
		free_timg(textures->east_tex, ptr);
		textures->east_tex = NULL;
	}
	free(textures);
}
