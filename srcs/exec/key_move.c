/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:19:47 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/27 00:14:15 by mmeguedm         ###   ########.fr       */
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
	data->player.ipx = data->player.pos_x / 75.0f;
	data->player.ipx_add_xo = (data->player.pos_x + data->player.x_offset) / 75.0f;
	data->player.ipx_sub_xo = (data->player.pos_x - data->player.x_offset) / 75.0f;

	data->player.ipy = data->player.pos_y / 75.0f;
	data->player.ipy_add_yo = (data->player.pos_y + data->player.y_offset) / 75.0f;
	data->player.ipy_sub_yo = (data->player.pos_y - data->player.y_offset) / 75.0f;
}

void	up_move(t_data *data)
{
	int	value1;
	int	value2;

	init_collision(data);
	value1 = (data->player.ipy * data->map.mapX) + data->player.ipx_sub_xo;
	value2 = (data->player.ipy_add_yo * data->map.mapX) + data->player.ipx;
	if (data->img.i_map[value1] == 0)
		data->player.pos_x -= data->player.pdx * 1.4;
	if (data->img.i_map[value2] == 0)
		data->player.pos_y -= data->player.pdy * 1.4;
}

void	down_move(t_data *data)
{
	int	value1;
	int	value2;

	init_collision(data);
	value1 = (data->player.ipy * data->map.mapX) + data->player.ipx_add_xo;
	value2 = (data->player.ipy_sub_yo * data->map.mapX) + data->player.ipx;

	if (data->img.i_map[value1] == 0)
		data->player.pos_x += data->player.pdx * 1.4;
	if (data->img.i_map[value2] == 0)
		data->player.pos_y += data->player.pdy * 1.4;
	// data->player.pos_x += data->player.pdx * 1.4;
	// data->player.pos_y += data->player.pdy * 1.4;
}


void	init_collision2(t_data *data, int px, int py)
{
	data->player.x_offset = 0;
	data->player.y_offset = 0;
	if (px < 0)
		data->player.x_offset = -10;
	else
		data->player.x_offset = +10;
	if (py < 0)
		data->player.y_offset = 10;
	else
		data->player.y_offset = -10;
	data->player.ipx = data->player.pos_x / 75.0f;
	data->player.ipx_add_xo = (data->player.pos_x + data->player.x_offset) / 75.0f;
	data->player.ipx_sub_xo = (data->player.pos_x - data->player.x_offset) / 75.0f;

	data->player.ipy = data->player.pos_y / 75.0f;
	data->player.ipy_add_yo = (data->player.pos_y + data->player.y_offset) / 75.0f;
	data->player.ipy_sub_yo = (data->player.pos_y - data->player.y_offset) / 75.0f;
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

	int	value1;
	int	value2;

	init_collision2(data, perpendicularx, perpendiculary);
	if (perpendicularx > 0.0f)
		value1 = (data->player.ipy * data->map.mapX) + data->player.ipx_add_xo;
	else
		value1 = (data->player.ipy * data->map.mapX) + data->player.ipx_sub_xo;
	if (perpendiculary > 0.0f)
		value2 = (data->player.ipy_sub_yo * data->map.mapX) + data->player.ipx;
	else
		value2 = (data->player.ipy_add_yo * data->map.mapX) + data->player.ipx;
	if (data->img.i_map[value1] == 0)
		data->player.pos_x += perpendicularx * 1.4;
	if (data->img.i_map[value2] == 0)
		data->player.pos_y += perpendiculary * 1.4;
}

void	left_move(t_data *data)
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

	int	value1;
	int	value2;

	init_collision2(data, perpendicularx, perpendiculary);
	if (perpendicularx > 0.0f)
		value1 = (data->player.ipy * data->map.mapX) + data->player.ipx_sub_xo;
	else
		value1 = (data->player.ipy * data->map.mapX) + data->player.ipx_add_xo;
	if (perpendiculary > 0.0f)
		value2 = (data->player.ipy_add_yo * data->map.mapX) + data->player.ipx;
	else
		value2 = (data->player.ipy_sub_yo * data->map.mapX) + data->player.ipx;
	if (data->img.i_map[value1] == 0)
		data->player.pos_x -= perpendicularx * 1.4;
	if (data->img.i_map[value2] == 0)
		data->player.pos_y -= perpendiculary * 1.4;
}
