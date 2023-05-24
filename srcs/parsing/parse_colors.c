/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:21:47 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/24 12:32:10 by mmeguedm         ###   ########.fr       */
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
		printf("Test\n");
		exit_error(E_TEXTURES);
	}
}

void	check_colors(t_data *data)
{
	char	**rgb;
	int		i;
	int		j;
	char	**paths;

	i = 5;
	while (i > 3)
	{
		j = 0;
		paths = init_var(data);
		rgb = ft_split(paths[i], ',');
		free(paths);
		while (rgb[j])
		{
			isnumber(rgb, rgb[j], data);
			j++;
		}
		free_split_rgb(rgb);
		if (j != 3)
		{
			free_map(data);
			exit_error(E_TEXTURES);
		}
		i--;
	}
}

