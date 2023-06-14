/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:31:38 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/14 18:19:47 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void draw_line(t_data *data, int i, int j, int color)
{
	int count;

	count = 0;
	while (count < data->player.case_width)
	{
		my_mlx_pixel_put(data, i + count, j, color);
		count++;
	}
}

static void draw_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	// data->player.pos_x += data->player.case_width / 2;
	// data->player.pos_y += data->player.case_height / 2;
	printf("pos_x : %f\tpos_y : %f\n", data->player.pos_x, data->player.pos_y);
	while (i < 10)
	{
		my_mlx_pixel_put(data, data->player.pos_x + i, data->player.pos_y, GREEN);
		my_mlx_pixel_put(data, data->player.pos_x - i, data->player.pos_y, GREEN);
		my_mlx_pixel_put(data, data->player.pos_x, data->player.pos_y + i, GREEN);
		my_mlx_pixel_put(data, data->player.pos_x, data->player.pos_y - i, GREEN);
		i++;
	}
}

static void draw_square(t_data *data, int axe_x, int axe_y, int color)
{
	int		count;
	
	count = 0;
	while (count < data->player.case_height)
	{
		draw_line(data, axe_x, axe_y + count, color);
		count++;
	}
}

static void draw_grid(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i <= WIDTH)
	{
		j = 0;
		while (j <= HEIGHT)
		{
			if (i % data->player.case_width == 0)
				my_mlx_pixel_put(data, i, j, WHITE);
			if (j % data->player.case_height == 0)
				my_mlx_pixel_put(data, i, j, WHITE);
			j++;
		}
		i++;
	}
}

void	get_cell_dim(t_data *data)
{
	int	map_x;
	int	map_y;
	
	map_x = get_longest_line(data->img.map);
	map_y = get_size_map(data->img.map);
	data->player.case_width = WIDTH / map_x;
	data->player.case_height = HEIGHT / map_y;
	data->player.pos_x = data->player.pos_x * data->player.case_width;
	data->player.pos_y = data->player.pos_y * data->player.case_height;
}

void draw_map(t_data *data)
{
	int i;
	int j;
	int longest_line;

	i = 0;
	while (data->img.map[i])
	{
		j = 0;
		while (data->img.map[i][j])
		{
			if (data->img.map[i][j] == '0')
				draw_square(data, j * data->player.case_width, i * data->player.case_height, BLUE);
			else if (data->img.map[i][j] == '1')
				draw_square(data, j * data->player.case_width, i * data->player.case_height, RED);
			else if (data->img.map[i][j] == 'N')
				draw_square(data, j * data->player.case_width, i * data->player.case_height, WHITE);
			j++;
		}
		i++;
	}
	draw_grid(data);
	draw_player(data);
	raycasting(data);
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.win_ptr, data->img.img_ptr, 0, 0);

}