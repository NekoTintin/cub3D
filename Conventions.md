# Map
- Maps en char.
- ' ' remplacés par '.' (plus facile pour la lecture de la map)

# Mini Doc pour les images:

```c
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
```

Tous les paramètres sont gérés par la minilibx.
NE JAMAIS FREE ADDR OU MLX_IMG -> utiliser ```free_timg()```

Pour init
```t_img	*init_new_image(void *mlx_ptr, int w, int h)```

Gérer les pixels
```void	put_pixel_to_img(t_img *img, int x, int y, int color)```

Des structs rectangles sont dispo pour aller plus vite:
```t_rect	*init_rectangle(int start_x, int start_y, int width, int height)```
```void	free_rectangle(t_rect *rect)```