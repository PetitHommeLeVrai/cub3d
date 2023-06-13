/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:31:38 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/13 17:38:27 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void	draw_square(t_data *data, int i, int j, int color)
{

	int	line;
	int	column;
	int	stop_value;
	int	stop_value2;


	line = i * 40;
	stop_value2 = line + 40;
	while (line < stop_value2)
	{
		column = j * 40;
		stop_value = column + 40;
		while (column < stop_value)
		{
			my_mlx_pixel_put(data, line, column, color);
			printf("column : %d\n", column);
			column++;
		}
		line++;
	}
}

static void	draw_line(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
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

void	draw_map(t_data *data)
{
	int	i;
	int	j;
	
	static char	*world_map[5] = {
		"111111111",
		"100000001",
		"100000001",
		"100000001",
		"111111111"
	};
	
	i = 0;
	while (world_map[i])
	{
		j = 0;
		while (world_map[i][j])
		{
			printf("value : %c\n", world_map[i][j]);
			if (world_map[i][j] == '0')
			{
				draw_square(data, i, j, RED);
			}
			else if (world_map[i][j] == '1')
				draw_square(data, i, j, BLUE);
			
			j++;
		}
		i++;
	}
	draw_line(data);
}