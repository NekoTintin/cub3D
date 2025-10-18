/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:35:26 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/15 17:48:44 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

typedef struct s_minimap
{
	void	*ptr;
	void	*win;
	int		width;
	int		height;
	int		tile_size;
}			t_minimap;

int	display_map_window(t_map *map);