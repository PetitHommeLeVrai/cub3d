/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:03:16 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/22 17:19:56 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_line(t_data *data)
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

void draw_line_with_coord(t_data *data, int x1, int y1, int x2, int y2, int color)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	sx = (x1 < x2) ? 1 : -1;
	sy = (y1 < y2) ? 1 : -1;
	err = dx - dy;
	while (1)
	{
		my_mlx_pixel_put(data, x1, y1, color);
		if (x1 == x2 && y1 == y2)
			break;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void	rotate_line(t_data *data)
{
	float	radians;
	int		x1;
	int		x2;
	int		y1;

	radians = data->player.p_a * (3.14159f / 180.0f);
	// printf("p_a : %f\n", data->player.p_a);
	// printf("radians : %f\n", radians);
	x1 = data->player.pos_x - 15;
	x2 = data->player.pos_x + 15;
	y1 = data->player.pos_y;

	data->player.x1 = data->player.pos_x  + (x1 - data->player.pos_x) * cosf(radians) - (y1 - data->player.pos_y) * sinf(radians);
	data->player.y2 = data->player.pos_y + (x1 - data->player.pos_x) * sinf(radians) + (y1 - data->player.pos_y) * cosf(radians);
	data->player.x2 = data->player.pos_x + (x2 - data->player.pos_x) * cosf(radians) - (y1 - data->player.pos_y) * sinf(radians);
	data->player.y1 = data->player.pos_y + (x2 - data->player.pos_x) * sinf(radians) + (y1 - data->player.pos_y) * cosf(radians);

	draw_line(data);
}
