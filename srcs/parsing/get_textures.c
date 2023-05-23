/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:40:53 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/05/22 18:22:03 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_path(t_data *data, char *key, char *path)
{
	if (!key)
		return ;
	if (ft_strncmp("NO", key, 2) == 0)
		data->img.n_path = ft_strdup(path);
	if (ft_strncmp("SO", key, 2) == 0)
		data->img.s_path = ft_strdup(path);
	if (ft_strncmp("WE", key, 2) == 0)
		data->img.w_path = ft_strdup(path);
	if (ft_strncmp("EA", key, 2) == 0)
		data->img.e_path = ft_strdup(path);
	if (ft_strncmp("F ", key, 2) == 0)
		data->img.f_color = ft_strdup(path);
	if (ft_strncmp("C ", key, 2) == 0)
		data->img.c_color = ft_strdup(path);
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

void	get_textures(t_data *data)
{
	int					i;
	int					j;
	static char			**key;
	int					k;

	key = init_key();
	i = 0;
	while (data->img.file[i])
	{
		k = 0;
		j = 0;
		while (key[j])
		{
			if (ft_strncmp(data->img.file[i], key[j], 2) == 0)
			{
				while (data->img.file[i][k] && data->img.file[i][k] != ' ')
					k++;
				while (data->img.file[i][k] && data->img.file[i][k] == ' ')
					k++;
				set_path(data, key[j], data->img.file[i] + k);
			}
			j++;
		}
		i++;
	}
}
