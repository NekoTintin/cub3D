/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:22:49 by qupollet          #+#    #+#             */
/*   Updated: 2026/01/02 18:01:17 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	close_window(t_game *game)
{
	ft_printf("Exiting the game...\n");
	ft_printf("Goodbye!\n");
	free_tgame(game);
	exit(0);
}

t_wdata	*create_win_data(void)
{
	t_wdata	*data;

	data = ft_calloc(1, sizeof(t_wdata));
	if (!data)
		return (NULL);
	data->ptr = NULL;
	data->win = NULL;
	data->win_width = WIN_WIDTH;
	data->win_height = WIN_HEIGHT;
	data->tex_size = TEXTURE_SIZE;
	data->textures = create_tex_struct();
	if (!data->textures)
		return (free(data), NULL);
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
	game->wdata->win = mlx_new_window(game->wdata->ptr, WIN_WIDTH,
			WIN_HEIGHT, "cub3D");
	if (!game->wdata->win)
		return (free(game->wdata->ptr),
			ft_print_error("Failed to create window"), -1);
	return (0);
}
