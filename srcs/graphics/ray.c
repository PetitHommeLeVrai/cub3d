/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:34:01 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/16 16:38:06 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static bool	hit_wall(t_data *data)
// {

// }

void	send_ray(t_data *data)
{
	int		r;
	int		mx;
	int		mp;
	int		my;
	int		dof;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;


}

void	start_pos_to_rad(t_data *data)
{
	if (data->player.compass_point == 'N')
		data->player.p_a = 270;
	else if (data->player.compass_point == 'S')
		data->player.p_a = 90;
	else if (data->player.compass_point == 'W')
		data->player.p_a = 180;
	else if (data->player.compass_point == 'E')
		data->player.p_a = 0;
	data->player.pdx = cos(degToRad(data->player.p_a));
	data->player.pdy = sin(degToRad(data->player.p_a));
}

void	raycasting(t_data *data)
{
	// int		i;
	double	distSide_Y;

	// i = 0;
	// float x = data->player.pos_x + data->player.case_width / 2;
	float y = 750;
	distSide_Y = data->player.case_height - fmod(y, data->player.case_height);
	float xn = distSide_Y / (tan(data->player.p_a));
	printf("distSide_Y : %f\n", distSide_Y);
	printf("yn : %f\n", xn);
	printf("%f\n", data->player.pos_y);
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
