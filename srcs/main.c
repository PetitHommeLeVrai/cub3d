/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:28:56 by aboyer            #+#    #+#             */
/*   Updated: 2023/07/14 15:21:44 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_pos(t_data *data, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
			{
				data->player.pos_x = x;
				data->player.pos_y = y;
				if (map[y][x] == 'N')
				{
					data->ray.dirx = -1.0;
					data->ray.diry = 0.0;
					data->ray.planex = 0.0;
					data->ray.planey = 0.66;
				}
				if (map[y][x] == 'S')
				{
					data->ray.dirx = 1.0;
					data->ray.diry = 0.0;
					data->ray.planex = 0.0;
					data->ray.planey = -0.66;
				}
				if (map[y][x] == 'E')
				{
					data->ray.dirx = 0.0;
					data->ray.diry = 1.0;
					data->ray.planex = 0.66;
					data->ray.planey = 0.0;
				}
				if (map[y][x] == 'W')
				{
					data->ray.dirx = 0.0;
					data->ray.diry = -1.0;
					data->ray.planex = -0.66;
					data->ray.planey = 0.0;
				}
				return (1);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	init(&data, ac, av);
	get_cell_dim(&data);
	data.player.pos_x += data.player.case_width - 10;
	data.player.pos_y += data.player.case_height - 100;
	get_pos(&data, data.img.map);
	draw_map(&data);
	mlx_loop(data.img.mlx_ptr);
}
