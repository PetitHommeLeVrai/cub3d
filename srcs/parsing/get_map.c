/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:57:32 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/13 20:39:59 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_size_map(char **file)
{
	int	i;
	
	i = 0;
	while (file && file[i])
		i++;
	return (i);
}

void	get_map(t_data *data)
{
	int		i;
	int		j;
	
	j = 0;
	i = data->txt.count;
	while (data->img.file[i][0] == 0)
		i++;
	data->img.map = malloc((sizeof(char *) * (get_size_map(data->img.file))));
	data->txt.count = i;
	while (data->img.file[i])
	{
		data->img.map[j] = ft_strdup(data->img.file[i]);
		i++;
		j++;
	}
	data->img.map[j] = NULL;
}

void	get_position_player(t_data *data)
{
	int		i;
	int		j;
	int		k;
	char	*start_pos_player;

	start_pos_player = "NSEW";
	i = 0;
	get_map(data);
	while (data->img.map[i])
	{
		j = 0;
		while (data->img.map[i][j])
		{
			k = 0;
			while (start_pos_player[k])
			{
				if (start_pos_player[k] == data->img.map[i][j])
					return ;
				k++;
			}
			data->player.pos_x++;
			j++;
		}
		data->player.pos_x = 0;
		data->player.pos_y++;
		i++;
	}
}

int	get_longest_line(char **map)
{
	int	longest_line;
	int	i;
	int	j;

	i = 0;
	longest_line = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (longest_line < j)
			longest_line = j;
		i++;
	}
	return (longest_line);
}