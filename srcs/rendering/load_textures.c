/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:43:01 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/18 17:45:54 by qupollet         ###   ########.fr       */
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
	tex->ceiling_color = -1;
	tex->floor_color = -1;
	return (tex);
}

int	load_textures(t_game *game)
{
	game->wdata->textures->north_tex = mlx_xpm_file_to_image(game->wdata->ptr,
			game->map->north, &game->wdata->tex_size,
			&game->wdata->tex_size);
	if (!game->wdata->textures->north_tex)
		return (ft_print_error("Failed to load North texture"), -1);
	game->wdata->textures->south_tex = mlx_xpm_file_to_image(game->wdata->ptr,
			game->map->south, &game->wdata->tex_size,
			&game->wdata->tex_size);
	if (!game->wdata->textures->south_tex)
		return (ft_print_error("Failed to load South texture"), -1);
	game->wdata->textures->west_tex = mlx_xpm_file_to_image(game->wdata->ptr,
			game->map->west, &game->wdata->tex_size,
			&game->wdata->tex_size);
	if (!game->wdata->textures->west_tex)
		return (ft_print_error("Failed to load West texture"), -1);
	game->wdata->textures->east_tex = mlx_xpm_file_to_image(game->wdata->ptr,
			game->map->east, &game->wdata->tex_size,
			&game->wdata->tex_size);
	if (!game->wdata->textures->east_tex)
		return (ft_print_error("Failed to load East texture"), -1);
	return (0);
}

void	free_textures(t_textures *textures, void *ptr)
{
	if (!textures)
		return ;
	if (textures->north_tex)
	{
		mlx_destroy_image(ptr, textures->north_tex);
		textures->north_tex = NULL;
	}
	if (textures->south_tex)
	{
		mlx_destroy_image(ptr, textures->south_tex);
		textures->south_tex = NULL;
	}
	if (textures->west_tex)
	{
		mlx_destroy_image(ptr, textures->west_tex);
		textures->west_tex = NULL;
	}
	if (textures->east_tex)
	{
		mlx_destroy_image(ptr, textures->east_tex);
		textures->east_tex = NULL;
	}
	free(textures);
}
