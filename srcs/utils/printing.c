/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:16:21 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/18 19:01:32 by qupollet         ###   ########.fr       */
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

void	print_tab(char **tab)
{
	int		idx;

	if (!tab)
		return ;
	idx = 0;
	ft_printf("----- Printing Tab -----\n");
	while (tab[idx])
	{
		ft_printf("%s\n", tab[idx]);
		idx++;
	}
	ft_printf("----- End of Tab -----\n");
}

void	print_map(t_map *map)
{
	if (!map || !map->grid)
		return ;
	print_tab(map->grid);
}
