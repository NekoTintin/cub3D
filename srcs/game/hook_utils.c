/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 20:20:41 by qupollet          #+#    #+#             */
/*   Updated: 2026/01/11 20:24:48 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	apply_player_mouvement(t_game *game, double move_x, double move_y)
{
	double	normalized;

	normalized = sqrt(move_x * move_x + move_y * move_y);
	if (normalized > 0)
	{
		move_x /= normalized;
		move_y /= normalized;
	}
	game->player->pos_x += move_x * PLAYER_MOVE_SPEED;
	game->player->pos_y += move_y * PLAYER_MOVE_SPEED;
}
