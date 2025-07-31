/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:38:04 by qupollet          #+#    #+#             */
/*   Updated: 2025/07/31 17:44:51 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_print_warning("Usage: ./cub3D <map_file>");
		return (1);
	}
	(void)argv; // To avoid unused parameter warning
	// Load the map file and initialize the game
	return (0);
}