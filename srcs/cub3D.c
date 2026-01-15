/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:38:04 by qupollet          #+#    #+#             */
/*   Updated: 2026/01/15 11:31:02 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_game		*game;

	if (argc != 2)
	{
		ft_print_error("Usage: ./cub3D <map_file>");
		return (1);
	}
	game = ft_parsing(argv[1]);
	if (!game)
		return (1);
	set_start_dir(game);
	game_start(game);
	free_tgame(game);
	return (0);
}
