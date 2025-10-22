/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:38:04 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/22 20:54:45 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_game		*game;

	if (argc != 2)
	{
		ft_print_warning("Usage: ./cub3D <map_file>");
		return (1);
	}
	game = ft_parsing(argv[1]);
	if (!game)
		return (1);
	display_map_window(game->map);
	free_tgame(game);
	return (0);
}
