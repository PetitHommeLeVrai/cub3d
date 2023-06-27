/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:25:42 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/27 12:47:07 by mmeguedm         ###   ########.fr       */
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
	
}