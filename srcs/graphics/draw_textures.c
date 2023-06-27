/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:25:42 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/27 16:14:35 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// t_pic    *new_pic(t_game *img, int width, int height, int x)
// {
//     t_pic    *new;
//     int        bpp;
//     int        endian;

//     bpp = 32;
//     endian = 1;
//     new = malloc(sizeof(t_pic));
//     new->width = width;
//     new->height = height;
//     if (x == 1)
//         new->img = mlx_xpm_file_to_image(img->mlx, img->sprite.north, \
//         &new->width, &new->height);
//     else if (x == 2)
//         new->img = mlx_xpm_file_to_image(img->mlx, img->sprite.east, \
//         &new->width, &new->height);
//     else if (x == 3)
//         new->img = mlx_xpm_file_to_image(img->mlx, img->sprite.west, \
//         &new->width, &new->height);
//     else if (x == 4)
//         new->img = mlx_xpm_file_to_image(img->mlx, img->sprite.sud, \
//         &new->width, &new->height);
//     else
//         new->img = mlx_new_image(img->mlx, width, height);
//     new->buf = (int *)mlx_get_data_addr(new->img, &bpp, &x, &endian);
//     return (new);
// }

void	put_texture(t_data *data)
{
	char	*img;
	int		width;
	int		height;

	printf("Test\n");
	width = ;
	height = 600;
    img = mlx_xpm_file_to_image(data->img.mlx_ptr, data->img.n_path, &width, &height);
	if (!img)
		exit_error(E_MLX);
	// mlx_put_image_to_window(data->img.mlx_ptr, data->img.win_ptr, data->img.img_ptr, 0, 0);
}