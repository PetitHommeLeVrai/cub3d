/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:20:42 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/07/18 18:34:38 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	r_rotate(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->ray.dir_x;
	old_plane_x = data->ray.plane_x;
	data->ray.dir_x = data->ray.dir_x * cos(-0.1) - data->ray.diry * sin(-0.1);
	data->ray.diry = old_dir_x * sin(-0.1) + data->ray.diry * cos(-0.1);
	data->ray.plane_x = data->ray.plane_x
		* cos(-0.1) - data->ray.plane_y * sin(-0.1);
	data->ray.plane_y = old_plane_x * sin(-0.1) + data->ray.plane_y * cos(-0.1);
}

void	l_rotate(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->ray.dir_x;
	old_plane_x = data->ray.plane_x;
	data->ray.dir_x = data->ray.dir_x * cos(0.1) - data->ray.diry * sin(0.1);
	data->ray.diry = old_dir_x * sin(0.1) + data->ray.diry * cos(0.1);
	data->ray.plane_x = data->ray.plane_x
		* cos(0.1) - data->ray.plane_y * sin(0.1);
	data->ray.plane_y = old_plane_x * sin(0.1) + data->ray.plane_y * cos(0.1);
}
