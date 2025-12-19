/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:20:44 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/28 20:10:15 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	game_start(t_game *game)
{
	if (display_window(game) == -1)
		return (ft_print_error("Failed to display window"), -1);
	mlx_hook(game->wdata->win, 17, 0, close_window, game);
	mlx_key_hook(game->wdata->win, key_hook, game);
	render(game);
	update_mini_map(game);
	mlx_loop(game->wdata->ptr);
	return (0);
}
