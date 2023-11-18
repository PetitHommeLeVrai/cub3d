/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:30 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/07/18 17:51:45 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_pos_player(t_data *data, char *start_pos_player, int i)
{
	int		j;
	int		k;

	j = 0;
	while (data->img.map[i][j])
	{
		k = 0;
		while (start_pos_player[k])
		{
			if (start_pos_player[k] == data->img.map[i][j])
			{
				data->player.compass_point = data->img.map[i][j];
				return ;
			}
			k++;
		}
		data->player.pos_x++;
		j++;
	}
}

void	get_position_player(t_data *data)
{
	int		i;
	char	*start_pos_player;

	start_pos_player = "NSEW";
	i = 0;
	get_map(data);
	while (data->img.map[i])
	{
		check_pos_player(data, start_pos_player, i);
		data->player.pos_x = 0;
		data->player.pos_y++;
		i++;
	}
}

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
