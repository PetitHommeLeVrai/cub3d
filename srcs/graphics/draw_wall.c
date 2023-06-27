/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:27:47 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/27 19:55:12 by mmeguedm         ###   ########.fr       */
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

void	draw_wall(t_data *data, double ray_dist, int x, int hit_x, int hit_y)
{
	int wall_height;
	int wall_top;
	int wall_bottom;
	int y;
	int stop;
	int bpp;
	int size_line;
	int endian;

	int *pixels = (int *)mlx_get_data_addr(data->txt.img_north, &bpp, &size_line, &endian);
	double wallx;
	double dirx = cos(data->ray.ray_a);
	double diry = sin(data->ray.ray_a);
	if (data->map.wall == V_WALL)
		wallx = data->player.pos_x + ((data->map.mapY - data->player.pos_y + (1 - 4) / 2) / data->ray.ray_y) * data->ray.ray_x;
	else
		wallx = data->player.pos_y + ((data->map.mapX - data->player.pos_x + (1 - 4) / 2) / data->ray.ray_y) * data->ray.ray_y;
	// if (data->ray.disH > data->ray.disV)
	// 	wallx = hit_y + ray_dist * diry;
	// else
	// 	wallx = hit_x + ray_dist * dirx;
	wallx -= floor(wallx);
	int texX = (int)(wallx * 64);
	

	// var texX:Number = int(wallX * texWidth);
	if (data->map.wall == H_WALL && dirx > 0) {
		texX = 64 - texX - 1;
	}
	if (data->map.wall == V_WALL && diry < 0) {
		texX = 64 - texX - 1;
	}
	// if(side == 1 && diry < 0)
		// texX = texWidth - texX - 1;
	// int texX = wallx * 64;
	// texX = 64 - texX - 1;
	stop = x;
	wall_height = (int)((HEIGHT * 10) / (ray_dist));
	wall_top = (HEIGHT - wall_height) / 2;
	double step = 64.0f / wall_height;
	if (wall_top <= 0)
		wall_top = 0;
	wall_bottom = wall_top + wall_height;
	if (wall_bottom >= HEIGHT)
		wall_bottom = HEIGHT - 1;
	double texPos = (wall_top - HEIGHT / 2 + wall_height / 2) * step;
	while (x < stop + 10)
	{
		y = 0;
		while (y < wall_top)
		{
			my_mlx_pixel_put2(data, x, y, data->txt.c_color);
			y++;
		}
		while (y >= wall_top && y <= wall_bottom)
		{
			// int texY = (int)texPos & (64 - 1);
			int texY = (y * 2  - HEIGHT  + wall_height) * (64 / 2) / wall_height + 1;
			// printf("texY : %d\n", texY);
			// if (texY < 0)
			// 	texY = 1;
			// texY = (position du pixel *2 – hauteur écran de projection + hauteur colonne)*(hauteur texture / 2) / hauteur colonne 
			texPos += step;
			// printf("texX : %d\n", texX);
			int color = pixels[64 * texY + texX];
			// printf("color: %d\n", color);
			my_mlx_pixel_put2(data, x, y, color);
			y++;
		}
		while (y < HEIGHT)
		{
			my_mlx_pixel_put2(data, x, y, data->txt.f_color);
			y++;
		}
		// printf("NEW\n");
		x++;
	}
}
