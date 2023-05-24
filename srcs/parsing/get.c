/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:57:32 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/05/23 21:22:19 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_size_map(char **file)
{
	int	i;
	int	s_malloc;
	int	j;

	j = 22;
	s_malloc = 0;
	i = 0;
	while (file && file[i])
		i++;
	i--;
	while (j && file && file[i] && file[i][0])
	{
		j--;
		s_malloc++;
		i--;
	}
	return (s_malloc);
}

void	reverse_map(t_data *data, char **tmp_map, int j)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	data->img.map = malloc(sizeof(char *) * (get_size_map(data->img.file) + 1));
	j--;
	while (j >= 0)
	{
		data->img.map[i] = tmp_map[j];
		size++;
		j--;
		i++;
	}
	data->img.map[i] = NULL;
}

static void	get_map(t_data *data)
{
	int		i;
	int		j;
	char	**tmp_map;
	
	j = 0;
	i = 0;
	tmp_map = malloc((sizeof(char *) * (get_size_map(data->img.file) + 1)));
	while (data->img.file[i])
		i++;
	i--;
	while (data->img.file[i][0])
	{
		tmp_map[j] = ft_strdup(data->img.file[i]);
		i--;
		j++;
	}
	tmp_map[j] = NULL;
	reverse_map(data, tmp_map, j);
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

