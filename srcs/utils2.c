/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:56:59 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/14 18:01:14 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_tmap(game->map);
	if (game->data)
		free_win_data(game->data);
	if (game->player_pos)
		free(game->player_pos);
	free(game);
}