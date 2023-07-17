/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:31:38 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/07/11 14:09:26 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_line(t_data *data, int i, int j, int color)
{
	int	count;

	count = 0;
	while (count < data->player.case_width)
	{
		my_mlx_pixel_put(data, i + count, j, color);
		count++;
	}
}

static void	draw_square(t_data *data, int axe_x, int axe_y, int color)
{
	int	count;

	count = 0;
	while (count < data->player.case_height)
	{
		draw_line(data, axe_x, axe_y + count, color);
		count++;
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

static bool	check_player(char c)
{
	int		k;
	char	*str;

	k = 0;
	str = "NSEW";
	while (str[k])
	{
		if (c == str[k])
			return (true);
		k++;
	}
	return (false);
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;
	int	longest_line;

	i = 0;
	while (data->img.map[i])
	{
		j = 0;
		while (data->img.map[i][j])
		{
			if (data->img.map[i][j] == '0')
				draw_square(data, j * data->player.case_width,
					i * data->player.case_height, BLUE);
			else if (data->img.map[i][j] == '1')
				draw_square(data, j * data->player.case_width,
					i * data->player.case_height, RED);
			else if (check_player(data->img.map[i][j]))
				draw_square(data, j * data->player.case_width,
					i * data->player.case_height, BLUE);
			j++;
		}
		i++;
	}
	raycasting(data);
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.win2_ptr,
		data->img.img2_ptr, 0, 0);
}
