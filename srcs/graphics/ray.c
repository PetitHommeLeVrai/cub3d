/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:34:01 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/14 19:51:38 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static bool	hit_wall(t_data *data)
// {

// }


void	draw_line(t_data *data)
{
	int		dx;
	int		dy;
	int		i;
	float	x;
	float	y;
	float	xinc;
	float	yinc;

	dx = data->player.x2 - data->player.x1;
	dy = data->player.y2 - data->player.y1;
	x = data->player.pos_x;
	y = data->player.pos_y;
	i = -1;
	if (abs(dx) > abs(dy))
		i = abs(dx);
	else
		i = abs(dy);
	xinc = dx / (float)i;
	yinc = dy / (float)i;
	while (--i)
	{
		my_mlx_pixel_put(data, x, y, GREEN);
		x += xinc;
		y += yinc;
	}
}

void	rotate_line(t_data *data)
{
	float	radians;
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	radians = data->player.p_a * (3.14159f / 180.0f);
	x1 = data->player.pos_x - 300 / 2;
	y1 = data->player.pos_y;
	x2 = data->player.pos_x + 300 / 2;
	y2 = data->player.pos_y;

	data->player.x1 = data->player.pos_x  + (x1 - data->player.pos_x) * cosf(radians) - (y1 - data->player.pos_y) * sinf(radians);
	data->player.y1 = data->player.pos_y + (x1 - data->player.pos_x) * sinf(radians) + (y1 - data->player.pos_y) * cosf(radians);
	data->player.x2 = data->player.pos_x + (x2 - data->player.pos_x) * cosf(radians) - (y2 - data->player.pos_y) * sinf(radians);
	data->player.y2 = data->player.pos_y + (x2 - data->player.pos_x) * sinf(radians) + (y2 - data->player.pos_y) * cosf(radians);

	draw_line(data);
}

void	raycasting(t_data *data)
{
	// int		i;
	// double	distSide_Y;

	// i = 0;
	// distSide_Y = data->player.pos_y - ((data->player.pos_y / (double)data->player.case_height) * data->player.case_height);
	// // printf("case_height : %d\t", data->player.case_height);
	// // printf("pos_x : %f\tcase_height : %d\t", data->player.pos_x, data->player.case_height);
	// // printf("distSide_Y : %f\n", distSide_Y);
	// while (i < 500)
	// {
	// my_mlx_pixel_put(data, data->player.pos_x + i, data->player.pos_y - i, GREEN);
	// // my_mlx_pixel_put(data, data->player.pos_x, distSide_Y, GREEN);
	// // my_mlx_pixel_put(data, data->player.pos_x + 1, distSide_Y, GREEN);
	// // my_mlx_pixel_put(data, data->player.pos_x - 1, distSide_Y, GREEN);
	// // my_mlx_pixel_put(data, data->player.pos_x, distSide_Y + 1, GREEN);
	// // my_mlx_pixel_put(data, data->player.pos_x, distSide_Y - 1, GREEN);
	// 	i++;
	// }
	rotate_line(data);
}
