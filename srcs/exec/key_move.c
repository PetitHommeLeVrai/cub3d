/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:19:47 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/22 20:44:09 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_collision(t_data *data)
{
	data->player.x_offset = 0;
	data->player.y_offset = 0;
	if (data->player.pdx < 0)
		data->player.x_offset = -10;
	else
		data->player.x_offset = +10;
	if (data->player.pdy < 0)
		data->player.y_offset = 10;
	else
		data->player.y_offset = -10;
	data->player.ipx = data->player.pos_x / data->player.case_height;
	data->player.ipx_add_xo = (data->player.pos_x + data->player.x_offset) / data->player.case_height;
	data->player.ipx_sub_xo = (data->player.pos_x - data->player.x_offset) / data->player.case_height;
	
	data->player.ipy = data->player.pos_y / data->player.case_height;
	data->player.ipy_add_yo = (data->player.pos_y + data->player.y_offset) / data->player.case_height;
	data->player.ipy_sub_yo = (data->player.pos_y - data->player.y_offset) / data->player.case_height;
}

void	up_move(t_data *data)
{
	init_collision(data);
	if (data->img.i_map[data->player.ipy * data->map.mapX + data->player.ipx_add_xo] == 0)
		data->player.pos_x -= data->player.pdx * 1.4;
	if (data->img.i_map[data->player.ipy_add_yo * data->map.mapX + data->player.ipx] == 0)
		data->player.pos_y -= data->player.pdy * 1.4;
	
}

void	down_move(t_data *data)
{
	data->player.pos_x += data->player.pdx * 1.4;
	data->player.pos_y += data->player.pdy * 1.4;
}

void	right_move(t_data *data)
{
	float angle;
	float perpendicular_angle;
	float perpendicularx;
    float perpendiculary;
	float magnitude;

	angle = degToRad(data->player.p_a);
	perpendicular_angle = angle - PI / 2;
	perpendicularx = cos(perpendicular_angle);
	perpendiculary = -sin(perpendicular_angle);
	magnitude = sqrt(perpendicularx * perpendicularx + perpendiculary * perpendiculary);
	perpendicularx /= magnitude;
	perpendiculary /= magnitude;
	data->player.pos_x += 1.4 * perpendicularx;
	data->player.pos_y += 1.4 * perpendiculary;
}

void	left_move(t_data *data)
{
	float angle;
	float perpendicular_angle;
	float perpendicularx;
    float perpendiculary;
	float magnitude;

	angle = degToRad(data->player.p_a);
	perpendicular_angle = angle + PI / 2;
	perpendicularx = cos(perpendicular_angle);
	perpendiculary = -sin(perpendicular_angle);
	magnitude = sqrt(perpendicularx * perpendicularx + perpendiculary * perpendiculary);
	perpendicularx /= magnitude;
	perpendiculary /= magnitude;
	data->player.pos_x += 1.4 * perpendicularx;
	data->player.pos_y += 1.4 * perpendiculary;
}
