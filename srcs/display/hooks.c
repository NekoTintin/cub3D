/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:28:46 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/14 17:59:50 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		ft_printf("Escape key pressed, exiting...\n");
		close_window(game);
	}
	else if (keycode >= 65361 && keycode <= 65364)
		player_move(keycode, game->data);
	return (0);
}

int	player_move(int keycode, t_win_data *data)
{
	if (keycode == 65362)
		ft_printf("Up arrow key pressed\n");
	else if (keycode == 65364)
		ft_printf("Down arrow key pressed\n");
	else if (keycode == 65361)
		ft_printf("Left arrow key pressed\n");
	else if (keycode == 65363)
		ft_printf("Right arrow key pressed\n");
	(void)data;
	return (0);
}
