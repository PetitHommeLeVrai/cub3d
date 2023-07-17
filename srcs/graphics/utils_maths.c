/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:30:52 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/21 19:32:36 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int FixAng(int a){ if(a>359){ a-=360;} if(a<0){ a+=360;} return a;}

float degToRad(int a){ return a*PI/180.0;}

float distance(float ax, float ay, float bx, float by, float ang){ return cos(degToRad(ang))*(bx-ax)-sin(degToRad(ang))*(by-ay);}

int	get_surface_map(t_data *data)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (data->img.map[i])
	{
		size += ft_strlen(data->img.map[i]);
		i++;
	}
	return (size);
}

void	convert_map_to_int(t_data *data)
{
	int	i;
	int	j;
	int	index;

	index = 0;
	i = 0;
	data->img.i_map = malloc(sizeof(int) * (get_surface_map(data) + 1));
	while (data->img.map[i])
	{
		j = 0;
		while (data->img.map[i][j])
		{
			if (data->img.map[i][j] == '1' || data->img.map[i][j] == ' ')
				data->img.i_map[index] = 1;
			else
				data->img.i_map[index] = 0;
			index++;
			j++;
		}
		i++;
	}
	i = 0;
	index = 0;
}
