/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:26:45 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/07/18 19:24:41 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(unsigned char t, unsigned char r,
				unsigned char g, unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static char	**create_colors_map(void)
{
	static char	*colors_map[] = {
		"F ",
		"C "
	};

	return (colors_map);
}

static void	init_colors_path(t_data *data, char texture, char *path)
{
	if (texture == 'F')
		data->img.f_color = ft_strtrim(path + 2, " ");
	if (texture == 'C')
		data->img.c_color = ft_strtrim(path + 2, " ");
	data->txt.count++;
}

static bool	is_in_colors_map(char *str)
{
	static char	**colors_map;
	int			i;

	i = 0;
	colors_map = create_colors_map();
	if (!str || str[0] == 0)
		return (false);
	while (colors_map[i])
	{
		if (!(ft_strncmp(colors_map[i], str, 2)))
			return (true);
		i++;
	}
	return (false);
}

void	get_colors(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = data->txt.index_file;
	while (data->img.file[i] && data->txt.count < 6)
	{
		j = 0;
		while (is_wspace(data->img.file[i][j]))
			j++;
		if (is_in_colors_map(data->img.file[i] + j))
			init_colors_path(data, data->img.file[i][j], data->img.file[i] + j);
		else if (data->img.file[i][0] != 0 && !only_wspace(data->img.file[i]))
			return (free_map(data), exit_error(E_ELEMENT));
		i++;
	}
	data->txt.count = i;
	fill_colors(data);
	data->txt.c_color = create_trgb(0, data->img.c_rgb[0], data->img.c_rgb[1],
			data->img.c_rgb[2]);
	data->txt.f_color = create_trgb(0, data->img.f_rgb[0], data->img.f_rgb[1],
			data->img.f_rgb[2]);
}
