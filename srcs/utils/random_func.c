/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:26:07 by qupollet          #+#    #+#             */
/*   Updated: 2025/12/19 17:54:08 by qupollet         ###   ########.fr       */
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
