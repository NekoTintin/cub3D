/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:28:46 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/28 19:41:12 by qupollet         ###   ########.fr       */
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
		player_move(keycode, game->wdata);
	return (0);
}

int	player_move(int keycode, t_wdata *data)
{
	if (keycode == KEY_UP || keycode == KEY_W || keycode == KEY_Z)
		ft_printf("Up arrow key pressed\n");
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		ft_printf("Down arrow key pressed\n");
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		ft_printf("Left arrow key pressed\n");
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		ft_printf("Right arrow key pressed\n");
	(void)data;
	return (0);
}
