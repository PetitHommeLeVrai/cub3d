/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:19:47 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/19 17:55:13 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	up_move(t_data *data)
{
	data->player.pos_x -= data->player.pdx * 1.4;
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
