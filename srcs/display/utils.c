/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:40:30 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/07 10:49:21 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_win_data(t_win_data *data)
{
	if (!data)
		return ;
	if (data->win)
	{
		mlx_destroy_window(data->ptr, data->win);
		data->win = NULL;
	}
	if (data->ptr)
	{
		mlx_destroy_display(data->ptr);
		free(data->ptr);
		data->ptr = NULL;
	}
	free_tmap(data->map);
	free(data);
}
