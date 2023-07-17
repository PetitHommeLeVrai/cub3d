/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:21:47 by aboyer            #+#    #+#             */
/*   Updated: 2023/06/19 14:25:27 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split_rgb(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		free(rgb[i]);
		i++;
	}
	free(rgb);
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

static bool	rgb_is_number(char **f_rgb, char **c_rgb)
{
	int	i;

	i = 0;
	while (f_rgb[i] && c_rgb[i])
	{
		if ((!str_isnumber(f_rgb[i])) || (!str_isnumber(c_rgb[i])))
			return (false);
		i++;
	}
	return (true);
}

void	fill_colors(t_data *data)
{
	int		i;
	char	**f_rgb;
	char	**c_rgb;

	i = 0;
	f_rgb = ft_split(data->img.f_color, ',');
	if (!f_rgb)
		exit_error(E_NOMEM);
	c_rgb = ft_split(data->img.c_color, ',');
	if (!c_rgb)
		exit_error(E_NOMEM);
	if (!rgb_is_number(f_rgb, c_rgb))
		exit_error(E_COLORS);
	while (f_rgb[i] && c_rgb[i])
	{
		data->img.f_rgb[i] = ft_atoi(f_rgb[i]);
		data->img.c_rgb[i] = ft_atoi(c_rgb[i]);
		if ((data->img.f_rgb[i] < 0) || (data->img.f_rgb[i] > 255))
			return (free_split_rgb(f_rgb), free_split_rgb(c_rgb),
				exit_error(E_CVAL));
		if ((data->img.c_rgb[i] < 0) || (data->img.c_rgb[i] > 255))
			return (free_split_rgb(f_rgb), free_split_rgb(c_rgb),
				exit_error(E_CVAL));
		i++;
	}
	if (i != 3)
		exit_error(E_COLORS);
	free_split_rgb(f_rgb);
	free_split_rgb(c_rgb);
}
