/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:43:01 by qupollet          #+#    #+#             */
/*   Updated: 2026/01/15 11:40:47 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_textures	*create_tex_struct(void)
{
	t_textures		*tex;

	tex = ft_calloc(1, sizeof(t_textures));
	if (!tex)
		return (NULL);
	tex->north_tex = NULL;
	tex->south_tex = NULL;
	tex->west_tex = NULL;
	tex->east_tex = NULL;
	tex->ceiling_color[0] = 0;
	tex->ceiling_color[1] = 0;
	tex->ceiling_color[2] = 0;
	tex->floor_color[0] = 0;
	tex->floor_color[1] = 0;
	tex->floor_color[2] = 0;
	return (tex);
}

static void	get_colours_from_parsing(t_game *game)
{
	game->wdata->textures->ceiling_color[0] = game->map->ceiling[0];
	game->wdata->textures->ceiling_color[1] = game->map->ceiling[1];
	game->wdata->textures->ceiling_color[2] = game->map->ceiling[2];
	game->wdata->textures->floor_color[0] = game->map->floor[0];
	game->wdata->textures->floor_color[1] = game->map->floor[1];
	game->wdata->textures->floor_color[2] = game->map->floor[2];
}

static int	check_texture_loaded(t_game *game)
{
	if (!game->wdata->textures->north_tex
		|| !game->wdata->textures->south_tex
		|| !game->wdata->textures->west_tex
		|| !game->wdata->textures->east_tex)
	{
		ft_print_error("At least one texture failed to load.");
		return (-1);
	}
	return (0);
}

int	load_textures(t_game *game)
{
	int		w;
	int		h;

	get_colours_from_parsing(game);
	game->wdata->textures->north_tex = load_from_xpm(
			game->map->north, game->wdata->ptr, &w, &h);
	if (w != TEXTURE_SIZE || h != TEXTURE_SIZE)
		return (ft_print_error("North texture has an invalid size"), -1);
	game->wdata->textures->south_tex = load_from_xpm(
			game->map->south, game->wdata->ptr, &w, &h);
	if (w != TEXTURE_SIZE || h != TEXTURE_SIZE)
		return (ft_print_error("South texture has an invalid size"), -1);
	game->wdata->textures->west_tex = load_from_xpm(
			game->map->west, game->wdata->ptr, &w, &h);
	if (w != TEXTURE_SIZE || h != TEXTURE_SIZE)
		return (ft_print_error("West texture has an invalid size"), -1);
	game->wdata->textures->east_tex = load_from_xpm(
			game->map->east, game->wdata->ptr, &w, &h);
	if (w != TEXTURE_SIZE || h != TEXTURE_SIZE)
		return (ft_print_error("East texture has an invalid size"), -1);
	return (check_texture_loaded(game));
}
