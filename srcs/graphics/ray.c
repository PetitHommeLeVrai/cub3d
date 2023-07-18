/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:34:01 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/07/18 19:16:01 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*assign_texture(t_data *data, int side)
{
	int	*pixels;

	if (data->ray.raydir_y >= 0.0 && side == 1)
		pixels = (int *)mlx_get_data_addr(data->txt.img_east,
				&data->img.bpp, &data->img.size_line, &data->img.endian);
	else if (data->ray.raydir_y <= 0.0 && side == 1)
		pixels = (int *)mlx_get_data_addr(data->txt.img_west,
				&data->img.bpp, &data->img.size_line, &data->img.endian);
	else if (data->ray.raydir_x <= 0.0 && side == 0)
		pixels = (int *)mlx_get_data_addr(data->txt.img_north,
				&data->img.bpp, &data->img.size_line, &data->img.endian);
	else
		pixels = (int *)mlx_get_data_addr(data->txt.img_south,
				&data->img.bpp, &data->img.size_line, &data->img.endian);
	return (pixels);
}

static void	update_raycasting(t_data *data, int x)
{
	data->ray.camara_x = (2 * x) / (double)SCREENWIDTH - 1;
	data->ray.raydir_y = data->ray.diry + data->ray.plane_y
		* data->ray.camara_x;
	data->ray.raydir_x = data->ray.dir_x + data->ray.plane_x
		* data->ray.camara_x;
	data->ray.map_x = (int)data->player.pos_y;
	data->ray.map_y = (int)data->player.pos_x;
	if (data->ray.raydir_x == 0)
		data->ray.ddist_x = 1e30;
	else
		data->ray.ddist_x = fabs(1 / data->ray.raydir_x);
	if (data->ray.raydir_y == 0)
		data->ray.ddist_y = 1e30;
	else
		data->ray.ddist_y = fabs(1 / data->ray.raydir_y);
}

static int	hit_detection(t_data *data, int *side)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->ray.sd_x < data->ray.sd_y)
		{
			data->ray.sd_x += data->ray.ddist_x;
			data->ray.map_x += data->ray.stepx;
			*side = 0;
		}
		else
		{
			data->ray.sd_y += data->ray.ddist_y;
			data->ray.map_y += data->ray.stepy;
			*side = 1;
		}
		if (data->img.map[data->ray.map_x][data->ray.map_y] == '1')
		hit = 1;
	}
	return (hit);
}

static void	draw_pixels(t_data *data, int *pixels, int x)
{
	double	step;
	int		g;
	int		color;
	int		tex_y;

	g = 0;
	step = 1.0 * TEXHEIGHT / data->ray.line_height;
	extra_draw_pixels(data, x, step);
	g = data->ray.draw_start;
	while (g < data->ray.draw_end)
	{
		tex_y = (int)data->ray.tex_pos & (TEXHEIGHT - 1);
		data->ray.tex_pos += step;
		color = pixels[TEXHEIGHT * tex_y + data->ray.tex_x];
		my_mlx_pixel_put2(data, x, g, color);
		g++;
	}
	g = data->ray.draw_end;
	while (g < SCREENHEIGHT)
	{
		if (g >= 0)
			my_mlx_pixel_put2(data, x, g, data->txt.f_color);
		g++;
	}
}

void	raycasting(t_data *data)
{
	int	x;
	int	*pixels;
	int	side;

	x = 0;
	while (x < SCREENWIDTH)
	{
		update_raycasting(data, x);
		calculate_side_distances(data);
		if (!hit_detection(data, &side))
			continue ;
		pixels = assign_texture(data, side);
		if (side == 0)
			data->ray.pw_dist = (data->ray.sd_x - data->ray.ddist_x);
		else
			data->ray.pw_dist = (data->ray.sd_y - data->ray.ddist_y);
		calculate_line_height_and_draw_start_end(data);
		calculate_wall_x(data, side);
		calculate_tex_x(data, side);
		draw_pixels(data, pixels, x);
		x++;
	}
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.win2_ptr,
		data->img.img2_ptr, 0, 0);
}
