/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:57:32 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/05/31 13:37:03 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player_pos(t_data *data, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
				|| map[y][x] == 'W')
			{
				data->player.p_x = x;
				data->player.p_y = y;
				break ;
			}
			x++;
		}
		y++;
		x = 0;
	}
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
