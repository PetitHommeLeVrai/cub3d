/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:20:42 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/07/14 15:18:05 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	r_rotate(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->ray.dirx;
	old_plane_x = data->ray.planex;
	data->ray.dirx = data->ray.dirx * cos(-0.1) - data->ray.diry * sin(-0.1);
	data->ray.diry = old_dir_x * sin(-0.1) + data->ray.diry * cos(-0.1);
	data->ray.planex = data->ray.planex
		* cos(-0.1) - data->ray.planey * sin(-0.1);
	data->ray.planey = old_plane_x * sin(-0.1) + data->ray.planey * cos(-0.1);
}

void	l_rotate(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->ray.dirx;
	old_plane_x = data->ray.planex;
	data->ray.dirx = data->ray.dirx * cos(0.1) - data->ray.diry * sin(0.1);
	data->ray.diry = old_dir_x * sin(0.1) + data->ray.diry * cos(0.1);
	data->ray.planex = data->ray.planex
		* cos(0.1) - data->ray.planey * sin(0.1);
	data->ray.planey = old_plane_x * sin(0.1) + data->ray.planey * cos(0.1);
}
