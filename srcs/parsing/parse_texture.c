/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:16:56 by aboyer            #+#    #+#             */
/*   Updated: 2023/06/27 12:46:02 by mmeguedm         ###   ########.fr       */
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
		exit_error(E_NOMEM);
	}
	paths[0] = data->img.n_path;
	paths[1] = data->img.s_path;
	paths[2] = data->img.e_path;
	paths[3] = data->img.w_path;
	paths[4] = data->img.c_color;
	paths[5] = data->img.f_color;
	return (paths);
}

void	set_textures(t_data *data)
{
	int		fd;
	int		i;
	char	**paths;

	i = 0;
	paths = init_var(data);
	if (!data->img.n_path || !data->img.s_path || !data->img.e_path
		|| !data->img.w_path)
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
