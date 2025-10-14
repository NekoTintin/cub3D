/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:43:01 by qupollet          #+#    #+#             */
/*   Updated: 2025/10/14 17:55:26 by qupollet         ###   ########.fr       */
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
	tex->width = 128;
	tex->height = 128;
	return (tex);
}

int	load_textures(t_game *game)
{
	game->data->textures->north_tex = mlx_xpm_file_to_image(game->data->ptr,
			game->map->north, &game->data->textures->width,
			&game->data->textures->height);
	if (!game->data->textures->north_tex)
		return (ft_print_error("Failed to load North texture"), -1);
	game->data->textures->south_tex = mlx_xpm_file_to_image(game->data->ptr,
			game->map->south, &game->data->textures->width,
			&game->data->textures->height);
	if (!game->data->textures->south_tex)
		return (ft_print_error("Failed to load South texture"), -1);
	game->data->textures->west_tex = mlx_xpm_file_to_image(game->data->ptr,
			game->map->west, &game->data->textures->width,
			&game->data->textures->height);
	if (!game->data->textures->west_tex)
		return (ft_print_error("Failed to load West texture"), -1);
	game->data->textures->east_tex = mlx_xpm_file_to_image(game->data->ptr,
			game->map->east, &game->data->textures->width,
			&game->data->textures->height);
	if (!game->data->textures->east_tex)
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
