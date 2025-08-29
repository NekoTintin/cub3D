/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:40:40 by qupollet          #+#    #+#             */
/*   Updated: 2025/08/29 17:19:45 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_print_warning(char *msg)
{
	ft_putstr_fd(YELLOW "Warning: " END, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_print_error(char *msg)
{
	ft_putstr_fd(RED "Error: " END, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

void	free_tmap(t_map *map)
{
	int		idx;

	if (!map)
		return ;
	idx = 0;
	while (map->grid[idx])
	{
		free(map->grid[idx]);
		idx++;
	}
	free(map->grid);
	free(map);
}