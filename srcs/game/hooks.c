/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:28:46 by qupollet          #+#    #+#             */
/*   Updated: 2026/01/15 11:11:10 by qupollet         ###   ########.fr       */
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
	if (code == KEY_LEFT)
		game->player->move->cam_left = 1;
	if (code == KEY_RIGHT)
		game->player->move->cam_right = 1;
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
	if (code == KEY_LEFT)
		game->player->move->cam_left = 0;
	if (code == KEY_RIGHT)
		game->player->move->cam_right = 0;
	return (0);
}

static void	player_mouvement(t_game *game, double *move_x, double *move_y)
{
	if (game->player->move->forward)
	{
		*move_x += game->player->dir_x;
		*move_y += game->player->dir_y;
	}
	if (game->player->move->backward)
	{
		*move_x -= game->player->dir_x;
		*move_y -= game->player->dir_y;
	}
	if (game->player->move->right)
	{
		*move_x += game->player->plane_x;
		*move_y += game->player->plane_y;
	}
	if (game->player->move->left)
	{
		*move_x -= game->player->plane_x;
		*move_y -= game->player->plane_y;
	}
	apply_player_mouvement(game, *move_x, *move_y);
}

static void	player_camera(t_game *game)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	if (!game->player->move->cam_left && !game->player->move->cam_right)
		return ;
	rot_speed = PLAYER_ROT_SPEED;
	if (game->player->move->cam_left)
		rot_speed = -rot_speed;
	old_dir_x = game->player->dir_x;
	game->player->dir_x = game->player->dir_x * cos(rot_speed)
		- game->player->dir_y * sin(rot_speed);
	game->player->dir_y = old_dir_x * sin(rot_speed)
		+ game->player->dir_y * cos(rot_speed);
	old_plane_x = game->player->plane_x;
	game->player->plane_x = game->player->plane_x * cos(rot_speed)
		- game->player->plane_y * sin(rot_speed);
	game->player->plane_y = old_plane_x * sin(rot_speed)
		+ game->player->plane_y * cos(rot_speed);
}

int	hook_loop(t_game *game)
{
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	player_mouvement(game, &move_x, &move_y);
	player_camera(game);
	render(game);
	return (0);
}
