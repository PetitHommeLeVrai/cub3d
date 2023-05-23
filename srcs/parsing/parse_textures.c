/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:16:56 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/23 16:14:28 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**init_var(t_data *data)
{
	char	**paths;

	paths = (char **)malloc(6 * sizeof(char *));
	if (!paths)
	{
		free_map(data);
		exit_error(E_TEXTURES);
	}
	paths[0] = data->img.n_path;
	paths[1] = data->img.s_path;
	paths[2] = data->img.e_path;
	paths[3] = data->img.w_path;
	paths[4] = data->img.c_color;
	paths[5] = data->img.f_color;
	return (paths);
}

void	check_textures(t_data *data)
{
	int		fd;
	int		i;
	char	**paths;

	i = 0;
	paths = init_var(data);
	if (!data->img.n_path || !data->img.s_path || !data->img.e_path
		|| !data->img.w_path || !data->img.c_color || !data->img.f_color)
	{
		free_map(data);
		exit_error(E_TEXTURES);
	}
	while (i < 4)
	{
		fd = open(paths[i], O_RDONLY);
		if (fd < 0)
		{
			free(paths);
			free_map(data);
			exit_error(E_TEXTURES);
		}
		close(fd);
		i++;
	}
	free(paths);
}

static char	**init_key(void)
{
	static char	*key[] = {
		"NO",
		"SO",
		"WE",
		"EA",
		"F ",
		"C "};

	return (key);
}

void	set_path(t_data *data, char *key, char *path)
{
	if (!path || !path[0])
		return ;
	if (ft_strncmp("NO", key, 2) == 0)
		data->img.n_path = ft_strtrim(path, "\n");
	if (ft_strncmp("SO", key, 2) == 0)
		data->img.s_path = ft_strtrim(path, "\n");
	if (ft_strncmp("WE", key, 2) == 0)
		data->img.w_path = ft_strtrim(path, "\n");
	if (ft_strncmp("EA", key, 2) == 0)
		data->img.e_path = ft_strtrim(path, "\n");
	if (ft_strncmp("F ", key, 2) == 0)
		data->img.f_color = ft_strtrim(path, "\n");
	if (ft_strncmp("C ", key, 2) == 0)
		data->img.c_color = ft_strtrim(path, "\n");
}

void	get_textures(t_data *data)
{
	int			i;
	int			j;
	static char	**key;
	int			k;

	key = init_key();
	i = 0;
	while (data->img.map[i])
	{
		k = 0;
		j = 0;
		while (key[j])
		{
			if (ft_strncmp(data->img.map[i], key[j], 2) == 0)
			{
				while (data->img.map[i][k] && data->img.map[i][k] != ' ')
					k++;
				while (data->img.map[i][k] && data->img.map[i][k] == ' ')
					k++;
				set_path(data, key[j], data->img.map[i] + k);
			}
			j++;
		}
		i++;
	}
}
