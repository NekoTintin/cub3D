/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:22:49 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/07 10:51:36 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	close_window(t_win_data *data)
{
	free_win_data(data);
	exit(0);
}

t_win_data	*create_win_data(void)
{
	t_win_data	*data;

	data = ft_calloc(1, sizeof(t_win_data));
	if (!data)
		return (NULL);
	return (data);
}

int	display_window(t_map *map)
{
	t_win_data	*data;

	(void)map;
	data = create_win_data();
	if (!data)
		return (ft_print_error("Failed to allocate window data"), -1);
	data->ptr = mlx_init();
	if (!data->ptr)
		return (ft_print_error("Failed to initialize MLX"), -1);
	data->win = mlx_new_window(data->ptr, 1200, 900, "cub3D");
	if (!data->win)
		return (free(data->ptr), ft_print_error("Failed to create window"), -1);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->ptr);
	free_win_data(data);
	return (0);
}
