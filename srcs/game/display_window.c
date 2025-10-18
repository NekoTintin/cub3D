/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:22:49 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/18 17:56:05 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	close_window(t_game *game)
{
	free_tgame(game);
	exit(0);
}

t_wdata	*create_win_data(void)
{
	t_wdata	*data;
	
	data = ft_calloc(1, sizeof(t_wdata));
	if (!data)
		return (NULL);
	data->win_width = 1200;
	data->win_height = 900;
	data->tex_size = 64;
	return (data);
}

int	display_window(t_game *game)
{
	game->wdata = create_win_data();
	if (!game->wdata)
		return (ft_print_error("Failed to allocate window data"), -1);
	game->wdata->ptr = mlx_init();
	if (!game->wdata->ptr)
		return (ft_print_error("Failed to initialize MLX"), -1);
	game->wdata->win = mlx_new_window(game->wdata->ptr, 1200, 900, "cub3D");
	if (!game->wdata->win)
		return (free(game->wdata->ptr),
			ft_print_error("Failed to create window"), -1);
	return (0);
}
