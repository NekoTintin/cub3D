/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:35:26 by qupollet          #+#    #+#             */
/*   Updated: 2026/01/02 18:25:07 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

// Size + 2 for borders
# define MINIMAP_WIDTH 222
# define MINIMAP_HEIGHT 182
# define MINIMAP_TILE_SIZE 20
# define MINIMAP_MARGIN 15

// Colors
# define MINIMAP_WALL_COLOR 0x444444
# define MINIMAP_FLOOR_COLOR 0xE6E6E6
# define MINIMAP_EMPTY_COLOR 0x101010
# define MINIMAP_PLAYER_COLOR 0xFF4500

# include "cub3D.h"

// map_to_char.c
char	**map_to_char(t_game *game);

// mini_map.c
int		update_mini_map(t_game *game);

// print_minimap.c
void	map_to_minimap(t_game *game);

#endif