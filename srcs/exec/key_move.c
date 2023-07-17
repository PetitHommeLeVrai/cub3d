/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:19:47 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/07/14 14:42:50 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	up_move(t_data *data)
{
    if(data->img.map[(int)(data->player.pos_y + data->ray.dirx * 0.7 )][(int)(data->player.pos_x)] != '1') data->player.pos_y += data->ray.dirx * 0.2;
	if(data->img.map[(int)(data->player.pos_y)][(int)(data->player.pos_x + data->ray.diry * 0.7)] != '1') data->player.pos_x += data->ray.diry * 0.2;
}

void	down_move(t_data *data)
{
    if(data->img.map[(int)(data->player.pos_y - data->ray.dirx * 0.7)][(int)(data->player.pos_x)] != '1') data->player.pos_y -= data->ray.dirx* 0.2;
    if(data->img.map[(int)(data->player.pos_y)][(int)(data->player.pos_x - data->ray.diry * 0.7)] != '1') data->player.pos_x -= data->ray.diry * 0.2;
}

void	right_move(t_data *data)
{
	float angle;
	float deltax;
	float deltay;

	angle = atan2(data->ray.diry, data->ray.dirx);
    deltax = 0.2* sin(angle);
    deltay = -0.2 * cos(angle);
	if(data->img.map[(int)(data->player.pos_y + 0.5 * sin(angle))][(int)(data->player.pos_x)] != '1')
		data->player.pos_y += deltax;
	if(data->img.map[(int)(data->player.pos_y)][(int)(data->player.pos_x + -0.5 * cos(angle))] != '1')
		data->player.pos_x += deltay;
}

void	left_move(t_data *data)
{
	float angle;
	float deltax;
	float deltay;

	angle = atan2(data->ray.diry, data->ray.dirx);
    deltax = -0.2* sin(angle);
    deltay = 0.2 * cos(angle);
	
	if(data->img.map[(int)(data->player.pos_y + -0.5 * sin(angle))][(int)(data->player.pos_x)] != '1')
		data->player.pos_y += deltax;
	if(data->img.map[(int)(data->player.pos_y)][(int)(data->player.pos_x + 0.5 * cos(angle))] != '1')
		data->player.pos_x += deltay;
}
