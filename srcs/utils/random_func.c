/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:26:07 by qupollet          #+#    #+#             */
/*   Updated: 2026/01/05 20:38:50 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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

void	print_extension_error(char *file)
{
	int		start;

	start = 0;
	start = ft_strlen(file);
	while (start > 0 && file[start] != '.')
		start--;
	ft_putstr_fd(RED "Error: " END, 2);
	ft_putstr_fd("File is not a .cub file (found a ", 2);
	while (file[start])
	{
		ft_putchar_fd(file[start], 2);
		start++;
	}
	ft_putstr_fd(")\n", 2);
}
