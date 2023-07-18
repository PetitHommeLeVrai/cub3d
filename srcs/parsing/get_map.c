/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:57:32 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/07/18 17:50:46 by mmeguedm         ###   ########.fr       */
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
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'W' || map[y][x] == 'E')
				return (init_coord(data, map, x, y));
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

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

int	get_map_last_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
