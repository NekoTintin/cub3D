/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:54:08 by qupollet          #+#    #+#             */
/*   Updated: 2025/12/20 16:06:12 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGES_H
# define IMAGES_H

// Image struct
// Needed to create a buffer
// BPP = bits per pixel
// endian is the order of bytes (0 = little endian, 1 = big endian) 
// Do this because mlx_pixel_put is slow
// DO NOT free img directly, use mlx_destroy_image
// DO NOT free addr directly, it's managed by mlx
typedef struct s_img
{
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
	int				bytes_per_pixel;
}					t_img;

typedef struct s_rect
{
	int			start_x;
	int			start_y;
	int			width;
	int			height;
}				t_rect;

// free_imgs.c
void				free_timg(t_img *img, void *mlx_ptr);
void				free_rectangle(t_rect *rect);

// images_init.c
t_img				*init_new_image(void *mlx_ptr, int w, int h);
t_img				*load_from_xpm(char *filename, void *ptr,
						int *w, int *h);
t_rect				*init_rectangle(int start_x, int start_y, int width,
						int height);

// images_func.c
void				put_pixel_to_img(t_img *img, int x, int y, int color);
void				put_rectangle_to_img(t_img *img, int color, t_rect *rect);

#endif