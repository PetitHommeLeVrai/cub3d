/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:57:32 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/05/31 16:41:26 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_player_pos(t_data *data, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
					|| map[y][x] == 'W' || map[y][x] == 'E')
			{
				data->player.p_x = x;
				data->player.p_y = y;
				return (1);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

int	get_map_last_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_bigger_len(char **map)
{
	int	y;
	int	x;
	int	bigger;

	y = 0;
	bigger = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		if (x > bigger)
			bigger = x;
		y++;
	}
	return (bigger);
}
