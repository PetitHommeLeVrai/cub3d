/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:26:45 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/05/24 13:02:26 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	printf("str : %s\n", str);
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
			exit_error(E_ELEMENT);
		i++;
	}
	printf("f_color : %s\n", data->img.f_color);
	printf("c_color : %s\n", data->img.c_color);
}