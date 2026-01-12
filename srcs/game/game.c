/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:20:44 by qupollet          #+#    #+#             */
/*   Updated: 2026/01/12 16:32:04 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	game_start(t_game *game)
{
	if (display_window(game) == -1)
		return (ft_print_error("Failed to display window"), -1);
	mlx_hook(game->wdata->win, 17, 0, close_window, game);
	mlx_hook(game->wdata->win, 2, 1L << 0, key_pressed, game);
	mlx_hook(game->wdata->win, 3, 1L << 1, key_released, game);
	mlx_loop_hook(game->wdata->ptr, hook_loop, game);
	if (load_textures(game) == -1)
		return (close_window(game), -1);
	render(game);
	mlx_loop(game->wdata->ptr);
	return (0);
}
