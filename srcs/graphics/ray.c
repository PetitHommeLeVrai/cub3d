/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:34:01 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/19 16:21:56 by mmeguedm         ###   ########.fr       */
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

/*	Get the x coordinate of the nearest horizontal intersection  */
void	get_x_intersection(t_data *data)
{
	float	ra;
	float	rx;
	float	ry;
	float	atan;
	float	tan_ra;
	float	x_intersection;
	float	y_intersection;
	
	ra = degToRad(data->player.p_a);
	tan_ra = tan(ra);
	tan_ra = 1 / tan_ra;
	atan = -1 / tan(ra);
	//	Looking down
	// if (ra > PI)
	// {
    if(sin(ra) > 0.001)
	{
		ry=(((int)data->player.pos_y >> 6) << 6) -0.0001;
		printf("ry : %f\n", ry);
		rx=(data->player.pos_y -ry) * tan_ra + data->player.pos_x;
		x_intersection = -64.0f * tan_ra;
	}
	else if(sin(ra) < -0.001)
	{
		ry=(((int)data->player.pos_y >> 6) << 6) + 64.0f;
		rx=(data->player.pos_y-ry) * tan_ra + data->player.pos_x;
		x_intersection = 64.0f * tan_ra;
	}
	printf("x_intersection : %f\n", x_intersection);
}

/*	The main raycasting
	To know the distance of the player to the near wall  */
void	raycasting(t_data *data)
{
	// int		i;
	double	distSide_Y;

	// i = 0;
	// float x = data->player.pos_x + data->player.case_width / 2;
	float y = 750;
	distSide_Y = data->player.case_height - fmod(y, data->player.case_height);
	float xn = distSide_Y / (tan(data->player.p_a));
	// printf("distSide_Y : %f\n", distSide_Y);
	// printf("xn : %f\n", xn);
	get_x_intersection(data);
	// my_mlx_pixel_put(data, data->player.pos_x, xn, GREEN);
	// printf("%f\n", data->player.pos_y);
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
