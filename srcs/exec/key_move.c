/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:19:47 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/26 16:53:15 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_collision(t_data *data)
{
	printf("NEY_MOVE\n");
	data->player.x_offset = 0;
	data->player.y_offset = 0;
	if (data->player.pdx < 0)
	{
		printf("pdx < 0\n");
		data->player.x_offset = -10;
	}
	else
	{
		printf("pdx > 0\n");
		data->player.x_offset = +10;
	}
	if (data->player.pdy < 0)
	{
		printf("pdy < 0\n");
		data->player.y_offset = 10;
	}
	else
	{
		printf("pdy > 0\n");
		data->player.y_offset = -10;
	}
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
	printf("value 1 : %d\tvalue2 : %d\n", value1, value2);
	// printf("i_map[%d] : %d\n", data->img.i_map[value1]);
	if (data->img.i_map[value1] == 0)
	{
		printf("pos_x\n");
		data->player.pos_x -= data->player.pdx * 1.4;
	}
	if (data->img.i_map[value2] == 0)
	{
		printf("pos_y\n");
		data->player.pos_y -= data->player.pdy * 1.4;
	}

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
