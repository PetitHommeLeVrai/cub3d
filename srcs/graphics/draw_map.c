/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:31:38 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/13 22:26:07 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void draw_line(t_data *data, int i, int j, int color)
{
	int count;

	count = 0;
	while (count < 40)
	{
		my_mlx_pixel_put(data, i + count, j, color);
		count++;
	}
}

static void draw_player(t_data *data)
{
	double	case_width;
	double	case_height;
	int		map_x;
	int		map_y;
	
	map_x = get_longest_line(data->img.map);
	map_y = get_size_map(data->img.map);
	case_width = WIDTH / map_x;
	case_height = HEIGHT / map_y;
	data->player.pos_x = data->player.pos_x * case_width;
	data->player.pos_y = data->player.pos_y * case_height;

	printf("player_pos_x : %f\tplayer_pos_y : %f\n", data->player.pos_x, data->player.pos_y);
	int	i;
	int	j;

	i = 0;
	data->player.pos_x += 10;
	data->player.pos_y += 10;
	my_mlx_pixel_put(data, data->player.pos_x, data->player.pos_y, GREEN);
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
	while (count < 40)
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
			if (i % 40 == 0)
				my_mlx_pixel_put(data, i, j, WHITE);
			if (j % 40 == 0)
				my_mlx_pixel_put(data, i, j, WHITE);
			j++;
		}
		i++;
	}
}

void draw_map(t_data *data)
{
	int i;
	int j;
	int longest_line;

	longest_line = get_longest_line(data->img.map);
	i = 0;
	printf("longest_line :%d\n", longest_line);
	while (data->img.map[i])
	{
		j = 0;
		while (data->img.map[i][j])
		{
			if (data->img.map[i][j] == '0')
				draw_square(data, j * 40, i * 40, BLUE);
			else if (data->img.map[i][j] == '1')
				draw_square(data, j * 40, i * 40, RED);
			else if (data->img.map[i][j] == 'N')
				draw_square(data, j * 40, i * 40, WHITE);
			j++;
		}
		i++;
	}
	draw_grid(data);
	draw_player(data);
	raycasting(data);
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.win_ptr, data->img.img_ptr, 0, 0);

}