/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:28:46 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/29 18:43:03 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("Escape key pressed, exiting...\n");
		close_window(game);
	}
	else
		player_move(keycode, game);
	return (0);
}

int	player_move(int keycode, t_game *game)
{
	if (keycode == KEY_UP || keycode == KEY_W || keycode == KEY_Z)
		game->player->pos_y -= 1.0;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		game->player->pos_y += 1.0;
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		game->player->pos_x -= 1.0;
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		game->player->pos_x += 1.0;
	return (0);
}
