/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_geo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:14:45 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/07/18 17:31:49 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	init_coord(t_data *data, char **map, int x, int y)
{
	data->player.pos_x = x;
	data->player.pos_y = y;
	if (map[y][x] == 'N')
		init_north(data);
	if (map[y][x] == 'S')
		init_south(data);
	if (map[y][x] == 'E')
		init_east(data);
	if (map[y][x] == 'W')
		init_west(data);
	return (1);
}

void	init_north(t_data *data)
{
	data->ray.dirx = -1.0;
	data->ray.diry = 0.0;
	data->ray.planex = 0.0;
	data->ray.planey = 0.66;
}

void	init_south(t_data *data)
{
	data->ray.dirx = 1.0;
	data->ray.diry = 0.0;
	data->ray.planex = 0.0;
	data->ray.planey = -0.66;
}

void	init_west(t_data *data)
{
	data->ray.dirx = 0.0;
	data->ray.diry = 1.0;
	data->ray.planex = 0.66;
	data->ray.planey = 0.0;
}

void	init_east(t_data *data)
{
	data->ray.dirx = 0.0;
	data->ray.diry = -1.0;
	data->ray.planex = -0.66;
	data->ray.planey = 0.0;
}
