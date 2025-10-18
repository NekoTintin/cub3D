/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:40:30 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/15 17:13:16 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	init_tplayer(t_player *player, t_map *map)
{
	player->pos_x = map->start_x;
	player->pos_y = map->start_y;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	return (0);
}

void	free_win_data(t_win_data *data)
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
