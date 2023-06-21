/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:34:01 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/21 16:42:22 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_intersection(t_data *data, int ray_x, int ray_y, int color)
{
	int	i;

	i = 0;
	if (ray_x <= 0 || ray_x >= WIDTH)
		return ;
	if (ray_y <= 0 || ray_y >= HEIGHT)
		return ;
	//	Draw cross
	while (i < 10)
	{
		if (ray_x + i >= WIDTH || ray_x - i <= 0)
			return ;
		if (ray_y + i >= HEIGHT || ray_y - i <= 0)
			return ;
		my_mlx_pixel_put(data, ray_x + i, ray_y, color);
		my_mlx_pixel_put(data, ray_x - i, ray_y, color);
		my_mlx_pixel_put(data, ray_x, ray_y + i, color);
		my_mlx_pixel_put(data, ray_x, ray_y - i, color);
		i++;
	}
	draw_line_with_coord(data, data->player.pos_x, data->player.pos_y, ray_x, ray_y);
	// Draw x intersection
	// my_mlx_pixel_put(data, ray_x, data->player.pos_y, GREEN);
	// my_mlx_pixel_put(data, ray_x + 1, data->player.pos_y, GREEN);
	// my_mlx_pixel_put(data, ray_x - 1, data->player.pos_y, GREEN);
	// my_mlx_pixel_put(data, ray_x, data->player.pos_y + 1, GREEN);
	// my_mlx_pixel_put(data, ray_x, data->player.pos_y - 1, GREEN);

	// Draw y intersection
	// my_mlx_pixel_put(data, data->player.pos_x, ray_y, GREEN);
	// my_mlx_pixel_put(data, data->player.pos_x + 1, ray_y, GREEN);
	// my_mlx_pixel_put(data, data->player.pos_x - 1, ray_y, GREEN);
	// my_mlx_pixel_put(data, data->player.pos_x, ray_y + 1, GREEN);
	// my_mlx_pixel_put(data, data->player.pos_x, ray_y - 1, GREEN);
}

static int	get_surface_map(t_data *data)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (data->img.map[i])
	{
		size += ft_strlen(data->img.map[i]);
		i++;
	}
	return (size);
}

static void	convert_map_to_int(t_data *data)
{
	int	i;
	int	j;
	int	index;

	index = 0;
	i = 0;
	data->img.i_map = malloc(sizeof(int) * (get_surface_map(data) + 1));
	while (data->img.map[i])
	{
		j = 0;
		while (data->img.map[i][j])
		{
			if (data->img.map[i][j] == '1' || data->img.map[i][j] == ' ')
				data->img.i_map[index] = 1;
			else
				data->img.i_map[index] = 0;
			index++;
			j++;
		}
		i++;
	}
	i = 0;
	index = 0;
	//	Print Map
	// while (i < 8)
	// {
	// 	j = 0;
	// 	while (j < 8)
	// 	{
	// 		printf("%d", data->img.i_map[index]);
	// 		index++;
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
}

void	check_vertical_line(t_data *data)
{
	float	ray_a;
	float	ray_x;
	float	ray_y;
	float	atan;
	float	tan_ra;
	float	y_offset;
	float	x_offset;
	float	disH;
	float	disY;
	float	vx;
	float	vy;
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
	atan = -1.0f / tan(ray_a);
	//	Looking left
	if(cos(degToRad(ray_a)) > 0.001)
	{
		ray_x = (((int)data->player.pos_x / data->player.case_height) * data->player.case_height) + data->player.case_height;
		ray_y = ((int)data->player.pos_x - ray_x) * tan_ra + data->player.pos_y;
		x_offset = data->player.case_height;
		y_offset = -x_offset * tan_ra;
	}
	//	Looking right
	else if(cos(degToRad(ray_a)) < -0.001)
	{
		ray_x = (((int)data->player.pos_x / data->player.case_height) * data->player.case_height) - 0.0001;
		ray_y = ((int)data->player.pos_x - ray_x) * tan_ra + data->player.pos_y;
		x_offset = -data->player.case_height;
		y_offset = -x_offset * tan_ra;
	}
	else
	{
		ray_x = data->player.pos_x;
		ray_y = data->player.pos_y;
		dof = 8;
	}
	while(dof < 8)
	{
		mx = (int)(ray_x) / data->player.case_height;
		my = (int)(ray_y) / data->player.case_height;
		mp = my * mapX + mx;
		//	Hit Wall
		if(mp > 0 && mp < mapX * mapY && data->img.i_map[mp] == 1)
		{
			dof = 8;
			data->player.disV = cos(degToRad(ray_a)) * (ray_x - data->player.pos_x) - sin(degToRad(ray_a)) * (ray_y - data->player.pos_y);
			// printf("disV : %f\n", data->player.disV);
			draw_intersection(data, ray_x, ray_y, YELLOW);
		}
		//	Next Vertical
		else
		{
			ray_x += x_offset;
			ray_y += y_offset;
			dof++;
		}
	}
}

/*	Get the x coordinate of the nearest horizontal intersection  */
void	check_horizontal_line(t_data *data)
{
	float	ray_a;
	float	ray_x;
	float	ray_y;
	float	tan_ra;
	float	y_offset;
	float	x_offset;
	float	hx;
	float	hy;
	float	disH;
	float	disY;

	int		mapY;
	int		mapX;
	int		dof;
	int		mx;
	int		my;
	int		mp;

	hx = data->player.pos_x;
	hy = data->player.pos_y;
	disH = 100000;
	mapY = 8;
	mapX = 8;
	dof = 0;
	ray_a = FixAng(data->player.p_a);
	tan_ra = tan(degToRad(ray_a));
	tan_ra = 1.0f / tan_ra;
	//	Looking up
	if(sin(degToRad(ray_a)) > 0.001)
	{
		ray_y = (((int)data->player.pos_y / data->player.case_height) * data->player.case_height) - 0.0001;
		ray_x = ((int)data->player.pos_y - ray_y) * tan_ra + data->player.pos_x;
		y_offset = -data->player.case_height;
		x_offset = -y_offset * tan_ra;
	}
	//	Looking down
	else if(sin(degToRad(ray_a)) < -0.001)
	{
		ray_y = (((int)data->player.pos_y / data->player.case_height) * data->player.case_height) + data->player.case_height;
		ray_x = ((int)data->player.pos_y - ray_y) * tan_ra + data->player.pos_x;
		y_offset = data->player.case_height;
		x_offset = -y_offset * tan_ra;
	}
	else
	{
		ray_x = data->player.pos_x;
		ray_y = data->player.pos_y;
		dof = 8;
	}
	while(dof < 8)
	{
		mx = (int)(ray_x) / data->player.case_width;
		my = (int)(ray_y) / data->player.case_width;
		mp = my * mapX + mx;
		//	Hit Wall
		if(mp < mapX * mapY && data->img.i_map[mp] == 1)
		{
			draw_intersection(data, ray_x, ray_y, ORANGE);
			dof = 8;
			data->player.disH = cos(degToRad(ray_a)) * (ray_x - data->player.pos_x) - sin(degToRad(ray_a)) * (ray_y - data->player.pos_y);
			// printf("disH : %f\n", data->player.disH);
		}
		//	Next horizontal
		else
		{
			ray_x += x_offset;
			ray_y += y_offset;
			dof++;
		}
	}
}

/*	The main raycasting
	To know the distance of the player to the near wall  */
void	raycasting(t_data *data)
{
	convert_map_to_int(data);
	check_horizontal_line(data);
	check_vertical_line(data);
	//rotate_line(data);
}
