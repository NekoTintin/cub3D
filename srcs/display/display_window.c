/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:22:49 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/14 17:59:30 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	close_window(t_game *game)
{
	free_game(game);
	exit(0);
}

t_win_data	*create_win_data(void)
{
	t_win_data	*data;

	data = ft_calloc(1, sizeof(t_win_data));
	if (!data)
		return (NULL);
	return (data);
}

int	display_window(t_game *game)
{
	game->data = create_win_data();
	if (!game->data)
		return (ft_print_error("Failed to allocate window data"), -1);
	game->data->ptr = mlx_init();
	if (!game->data->ptr)
		return (ft_print_error("Failed to initialize MLX"), -1);
	game->data->win = mlx_new_window(game->data->ptr, 1200, 900, "cub3D");
	if (!game->data->win)
		return (free(game->data->ptr), ft_print_error("Failed to create window"), -1);
	mlx_hook(game->data->win, 17, 0, close_window, game->data);
	mlx_key_hook(game->data->win, key_hook, game);
	mlx_loop(game->data->ptr);
	return (0);
}
