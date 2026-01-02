/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:28:46 by qupollet          #+#    #+#             */
/*   Updated: 2026/01/02 18:58:26 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include <stdio.h>

int	key_pressed(int code, t_game *game)
{
	if (code == KEY_ESC)
		close_window(game);
	if (code == KEY_W || code == KEY_Z)
		game->player->move->forward = 1;
	if (code == KEY_S)
		game->player->move->backward = 1;
	if (code == KEY_A || code == KEY_Q)
		game->player->move->left = 1;
	if (code == KEY_D)
		game->player->move->right = 1;
	if (code == KEY_LEFT) // To be implemented
		;
	if (code == KEY_RIGHT)
		;
	return (0);
}

int	key_released(int code, t_game *game)
{
	if (code == KEY_W || code == KEY_Z)
		game->player->move->forward = 0;
	if (code == KEY_S)
		game->player->move->backward = 0;
	if (code == KEY_A || code == KEY_Q)
		game->player->move->left = 0;
	if (code == KEY_D)
		game->player->move->right = 0;
	if (code == KEY_LEFT) // To be implemented
		;
	if (code == KEY_RIGHT)
		;
	return (0);
}

static void	player_mouvement(t_game *game)
{
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	if (game->player->move->forward)
		move_y -= 1;
	if (game->player->move->backward)
		move_y += 1;
	if (game->player->move->left)
		move_x -= 1;
	if (game->player->move->right)
		move_x += 1;
	if (move_x != 0 && move_y != 0)
	{
		move_x *= sqrt(2) / 2;
		move_y *= sqrt(2) / 2;
	}
	game->player->pos_x += move_x * PLAYER_MOVE_SPEED;
	game->player->pos_y += move_y * PLAYER_MOVE_SPEED;
}

static void	player_camera(t_game *game)
{
	if (game->player->move->cam_left) // To be implemented
		;
	if (game->player->move->cam_right)
		;
}

int	hook_loop(t_game *game)
{
	player_mouvement(game);
	player_camera(game);
	render(game);
	return (0);
}
