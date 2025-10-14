/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:38:04 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/14 16:47:25 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// Aussi un test, à enlever plus tard
void	print_char_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

// Test, à enlever plus tard
void	print_map(t_map *map)
{
	int			i;

	if (!map)
		return ;
	i = 0;
	ft_printf("Map:\n");
	while (i < map->height)
	{
		ft_printf("%s\n", map->grid[i]);
		i++;
	}
	ft_printf("End of map\n");
}

int	main(int argc, char **argv)
{
	t_map		*map;

	if (argc != 2)
	{
		ft_print_warning("Usage: ./cub3D <map_file>");
		return (1);
	}
	map = ft_parsing(argv[1]);
	if (!map)
		return (1);
	display_window(map);
	return (0);
}
