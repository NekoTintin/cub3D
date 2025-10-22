/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:35:26 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/22 23:28:03 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3D.h"

typedef struct s_minimap
{
	void	*ptr;
	void	*win;
	int		width;
	int		height;
	int		tile_size;
	void	*screen_img;
}			t_minimap;

int	display_map_window(t_map *map);

int	mlx_detect_memory_order(t_img *img, int x, int y);
#endif