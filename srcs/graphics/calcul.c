/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:23:54 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/07/18 18:41:33 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_side_distances(t_data *data)
{
	if (data->ray.raydir_x < 0)
	{
		data->ray.stepx = -1;
		data->ray.sd_x = (data->player.pos_y - data->ray.map_x)
			* data->ray.ddist_x;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.sd_x = (data->ray.map_x + 1.0 - data->player.pos_y)
			* data->ray.ddist_x;
	}
	if (data->ray.raydir_y < 0)
	{
		data->ray.stepy = -1;
		data->ray.sd_y = (data->player.pos_x - data->ray.map_y)
			* data->ray.ddist_y;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.sd_y = (data->ray.map_y + 1.0 - data->player.pos_x)
			* data->ray.ddist_y;
	}
}

void	calculate_line_height_and_draw_start_end(t_data *data)
{
	data->ray.pitch = 100;
	data->ray.line_height = (int)(SCREENHEIGHT / data->ray.pw_dist);
	data->ray.draw_start = -data->ray.line_height / 2 + SCREENHEIGHT
		/ 2 + data->ray.pitch;
	if (data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = data->ray.line_height / 2 + SCREENHEIGHT
		/ 2 + data->ray.pitch;
	if (data->ray.draw_end >= SCREENHEIGHT)
		data->ray.draw_end = SCREENHEIGHT - 1;
}

void	calculate_wall_x(t_data *data, int side)
{
	if (side == 0)
		data->ray.wall_x = data->player.pos_x + data->ray.pw_dist
			* data->ray.raydir_y;
	else
		data->ray.wall_x = data->player.pos_y + data->ray.pw_dist
			* data->ray.raydir_x;
	data->ray.wall_x -= floor((data->ray.wall_x));
}

void	calculate_tex_x(t_data *data, int side)
{
	data->ray.tex_x = (int)(data->ray.wall_x * (double)(TEXWIDTH));
	if ((side == 0 && data->ray.raydir_x > 0)
		|| (side == 1 && data->ray.raydir_y < 0))
		data->ray.tex_x = TEXWIDTH - data->ray.tex_x - 1;
}

void	extra_draw_pixels(t_data *data, int x, double step)
{
	int	g;

	g = 0;
	data->ray.tex_pos = (data->ray.draw_start - data->ray.pitch - SCREENHEIGHT
			/ 2 + data->ray.line_height / 2) * step;
	while (g < data->ray.draw_start)
	{
		if (g < SCREENHEIGHT)
			my_mlx_pixel_put2(data, x, g, data->txt.c_color);
		g++;
	}
}
