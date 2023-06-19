/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:34:01 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/19 19:38:27 by mmeguedm         ###   ########.fr       */
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
	float	y_offset;


}

/*	Get the x coordinate of the nearest horizontal intersection  */
void	get_x_intersection(t_data *data)
{
	float	ray_a;
	float	ray_x;
	float	ray_y;
	float	atan;
	float	tan_ra;
	float	x_offset;
	float	y_offset;
	float	disH;
	float	disY;

	int		mapY;
	int		mapX;
	int		dof;
	int		mx;
	int		my;
	int		mp;
	
	mapY = 8;
	mapX = 8;
	dof = 0;
	ray_a = FixAng(data->player.p_a);
	tan_ra = tan(degToRad(ray_a));
	tan_ra = 1.0f / tan_ra;
	atan = -1.0f / tan(ray_a);
	//	Looking down
	// if (ray_a > PI)
	// {
	tan_ra = 1.0f / tan_ra;
	//	looking up 
	if(sin(degToRad(ray_a)) > 0.001)
	{
		printf("UP\n");
		ray_y = (((int)data->player.pos_y >> 6) << 6) - 0.0001f;
		ray_x = (data->player.pos_y - ray_y) * tan_ra + data->player.pos_x;
		y_offset = -64;
		x_offset = -y_offset * tan_ra;
		printf("ray_x : %f\tray_y : %f\n", ray_x, ray_y);
		printf("x_offset : %f\n\n", x_offset);
		my_mlx_pixel_put(data, data->player.pos_x, ray_y, GREEN);
		my_mlx_pixel_put(data, data->player.pos_x + 1, ray_y, GREEN);
		my_mlx_pixel_put(data, data->player.pos_x - 1, ray_y, GREEN);
		my_mlx_pixel_put(data, data->player.pos_x, ray_y + 1, GREEN);
		my_mlx_pixel_put(data, data->player.pos_x, ray_y - 1, GREEN);
	}
	//	looking down
	else if(sin(degToRad(ray_a)) < -0.001)
	{
		printf("DOWN\n");
		ray_y = (((int)data->player.pos_y >> 6) << 6 ) + 64;
		printf("ray_y : %f\n", ray_y);
		ray_x = (data->player.pos_y - ray_y) * tan_ra + data->player.pos_x;
		y_offset = 64;
		x_offset = -y_offset * tan_ra;
		printf("x_offset : %f\n", x_offset);
	}
	else
	{
		ray_x = data->player.pos_x;
		ray_y = data->player.pos_y;
		dof = 8;
	}
	while(dof < 8) 
	{ 
		mx = (int)(ray_x) >> 6;
		my = (int)(ray_y) >> 6;
		mp = my * mapX + mx;                          
		if(mp > 0 && mp < mapX * mapY && data->img.map[mp] == '1')
		{
			printf("Test\n");
			dof = 8;
			disH = cos(degToRad(ray_a)) * (ray_x - data->player.pos_x) - sin(degToRad(ray_a)) * (ray_y - data->player.pos_y);}//hit 
		else
		{
			ray_x += x_offset;
			ray_y += y_offset;
			dof++;
		}                                               //check next horizontal
	} 
  
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
