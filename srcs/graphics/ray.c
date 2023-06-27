/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:34:01 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/27 19:05:17 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	draw_intersection(t_data *data, int ray_x, int ray_y, int color)
{
	int	i;

	i = 0;
	if (ray_x <= 0 || ray_x >= WIDTH)
		return ;
	if (ray_y <= 0 || ray_y >= HEIGHT)
		return ;
	draw_line_with_coord(data, data->player.pos_x, data->player.pos_y, ray_x, ray_y, data->map.color);
}

static void	hit_wall(t_data *data, float ray_a, unsigned char flag, int a)
{
	int	dof;
	int	mx;
	int	my;
	int	mp;

	if (a)
		return ;
	dof = 0;
	while(dof < 8)
	{
		mx = (int)(data->ray.ray_x) / data->player.case_height;
		my = (int)(data->ray.ray_y) / data->player.case_height;
		mp = my * data->map.mapX + mx;
		//	Hit Wall
		if(mp > 0 && mp < data->map.mapX * data->map.mapY && data->img.i_map[mp] == 1)
		{
			dof = 8;
			if (flag & DISV)
				data->ray.disV = cos(degToRad(ray_a)) * (data->ray.ray_x - data->player.pos_x) - sin(degToRad(ray_a)) * (data->ray.ray_y - data->player.pos_y);
			else if (flag & DISH)
				data->ray.disH = cos(degToRad(ray_a)) * (data->ray.ray_x - data->player.pos_x) - sin(degToRad(ray_a)) * (data->ray.ray_y - data->player.pos_y);
		}
		//	Next Vertical
		else
		{
			data->ray.ray_x += data->ray.x_offset;
			data->ray.ray_y += data->ray.y_offset;
			dof++;
		}
	}
}

/*	Get the y coordinate of the nearest horizontal intersection  */
void	check_vertical_line(t_data *data, float	ray_a)
{
	float	tan_ra;
	int		a;

	a = 0;
	tan_ra = tan(degToRad(ray_a));
	//	Looking left
	if(cos(degToRad(ray_a)) > 0.001)
	{
		data->ray.ray_x = (((int)data->player.pos_x / data->player.case_height) * data->player.case_height) + data->player.case_height;
		data->ray.ray_y = ((int)data->player.pos_x - data->ray.ray_x) * tan_ra + data->player.pos_y;
		data->ray.x_offset = data->player.case_height;
		data->ray.y_offset = -data->ray.x_offset * tan_ra;
	}
	//	Looking right
	else if(cos(degToRad(ray_a)) < -0.001)
	{
		data->ray.ray_x = (((int)data->player.pos_x / data->player.case_height) * data->player.case_height) - 0.0001;
		data->ray.ray_y = ((int)data->player.pos_x - data->ray.ray_x) * tan_ra + data->player.pos_y;
		data->ray.x_offset = -data->player.case_height;
		data->ray.y_offset = -data->ray.x_offset * tan_ra;
	}
	else
	{
		data->ray.ray_x = data->player.pos_x;
		data->ray.ray_y = data->player.pos_y;
		a = 1;
	}
	hit_wall(data, ray_a, DISV, a);
	data->ray.vx = data->ray.ray_x;
	data->ray.vy = data->ray.ray_y;
}

/*	Get the x coordinate of the nearest horizontal intersection  */
void	check_horizontal_line(t_data *data, float ray_a)
{
	float	tan_ra;
	int		a;
	int		ca;

	data->map.color = RED;
	data->map.wall = H_WALL;
	tan_ra = 1.0f / tan(degToRad(ray_a));
	//	Looking up
	a = 0;
	if(sin(degToRad(ray_a)) > 0.001)
	{
		data->ray.ray_y = (((int)data->player.pos_y / data->player.case_height) * data->player.case_height) - 0.0001;
		data->ray.ray_x = ((int)data->player.pos_y - data->ray.ray_y) * tan_ra + data->player.pos_x;
		data->ray.y_offset = -data->player.case_height;
		data->ray.x_offset = -data->ray.y_offset * tan_ra;
	}
	//	Looking down
	else if(sin(degToRad(ray_a)) < -0.001)
	{
		data->ray.ray_y = (((int)data->player.pos_y / data->player.case_height) * data->player.case_height) + data->player.case_height;
		data->ray.ray_x = ((int)data->player.pos_y - data->ray.ray_y) * tan_ra + data->player.pos_x;
		data->ray.y_offset = data->player.case_height;
		data->ray.x_offset = -data->ray.y_offset * tan_ra;
	}
	else
	{
		data->ray.ray_x  = data->player.pos_x;
		data->ray.ray_y = data->player.pos_y;
		a = 1;
	}
	hit_wall(data, ray_a, DISH, a);
	if (data->ray.disV < data->ray.disH)
	{
		data->ray.ray_x = data->ray.vx;
		data->ray.ray_y = data->ray.vy;
		data->map.wall = V_WALL;
		data->map.color = GREEN;
		data->ray.disH = data->ray.disV;
	}
	ca = FixAng(data->player.p_a - ray_a);
	data->ray.disH = data->ray.disH * cos(degToRad(ca));
	draw_intersection(data, data->ray.ray_x, data->ray.ray_y, data->map.color);
}


/*	The main raycasting
	To know the distance of the player to the near wall  */
void	raycasting(t_data *data)
{
	float	ray_a;
	int		r;
	int		i;

	r = 0;
	i = 0;

	data->map.mapX = 8;
	data->map.mapY = 8;
	convert_map_to_int(data);
	ray_a = FixAng(data->player.p_a + 30.0f);
	while (r < 60)
	{
		data->ray.disH = 100000.0f;
		data->ray.disV = 100000.0f;
		check_vertical_line(data, ray_a);
		check_horizontal_line(data, ray_a);
		draw_color(data, ray_a);
		draw_wall(data, data->ray.disH, i, data->ray.ray_x, data->ray.ray_y);;
		r++;
		i += 10;
		ray_a = FixAng(ray_a - 1.0f);
	}
}
