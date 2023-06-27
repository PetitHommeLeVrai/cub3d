/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:27:47 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/27 12:21:44 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	draw_color(t_data *data, int ray_a)
{
	if (data->map.wall == H_WALL)
	{
		if (ray_a >= 0 && ray_a <= 180)
			data->map.color = RED1;
		else
			data->map.color = RED2;
	
	}
	else if (data->map.wall == V_WALL)
	{
		if (ray_a >= 90 && ray_a <= 270)
			data->map.color = YELLOW1;
		else
			data->map.color = YELLOW2;
	}
}

void	draw_wall(t_data *data, double ray_dist, int x)
{
	int wall_height;
	int wall_top;
	int wall_bottom;
	int y;
	int stop;

	stop = x;
	wall_height = (int)((HEIGHT * 10) / (ray_dist));
	wall_top = (HEIGHT - wall_height) / 2;
	if (wall_top <= 0)
		wall_top = 0;
	wall_bottom = wall_top + wall_height;
	if (wall_bottom >= HEIGHT)
		wall_bottom = HEIGHT - 1;
	while (x < stop + 10)
	{
		y = 0;
		while (y < wall_top)
		{
			my_mlx_pixel_put2(data, x, y, BLUE);
			y++;
		}
		while (y >= wall_top && y <= wall_bottom)
		{
			my_mlx_pixel_put2(data, x, y, data->map.color);
			y++;
		}
		while (y < HEIGHT)
		{
			my_mlx_pixel_put2(data, x, y, YELLOW);
			y++;
		}
		x++;
	}
}
