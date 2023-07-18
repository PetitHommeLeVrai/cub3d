/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:38:39 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/07/18 17:52:48 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	only_wspace(char *str)
{
	while (*str)
	{
		if (!is_wspace(*str))
			return (0);
		str++;
	}
	return (1);
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

void	isnumber(char **rgb, char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			free_split_rgb(rgb);
			free_map(data);
			exit_error(E_TEXTURES);
		}
		i++;
	}
	if (ft_atoi(str) < 0 || ft_atoi(str) > 255)
	{
		free_split_rgb(rgb);
		free_map(data);
		exit_error(E_TEXTURES);
	}
}

bool	str_isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
