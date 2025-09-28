/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:40:40 by qupollet          #+#    #+#             */
/*   Updated: 2025/09/28 20:12:46 by qupollet         ###   ########.fr       */
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

void	free_tab(char **tab)
{
	int		idx;

	idx = 0;
	while (tab[idx])
	{
		free(tab[idx]);
		idx++;
	}
	free(tab);
}

void	free_tmap(t_map *map)
{
	if (!map || !map->grid)
		return ;
	free_tab(map->grid);
	free(map->start);
	free(map);
}

void	remove_newline(char *str)
{
	int		idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '\n')
			str[idx] = '\0';
		idx++;
	}
}
