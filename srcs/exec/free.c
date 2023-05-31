/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:03:42 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/05/31 14:39:40 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_img(t_data *data)
{
	free(data->img.file);
	free(data->img.map);
	free(data->img.map_cp);
	free(data->img.n_path);
	free(data->img.s_path);
	free(data->img.e_path);
	free(data->img.w_path);
	free(data->img.c_color);
	free(data->img.f_color);
}

void	free_map(t_data *data)
{
	int	i;

	i = -1;
	if (data->img.file)
	{
		while (data->img.file[++i])
			free(data->img.file[i]);
	}
	i = -1;
	if (data->img.map)
	{
		while (data->img.map[++i])
			free(data->img.map[i]);
	}
	i = -1;
	if (data->img.map_cp)
	{
		while (++i < get_map_last_line(data->img.map))
			free(data->img.map_cp[i]);
	}
	free_img(data);
}
