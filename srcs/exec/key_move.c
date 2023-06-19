/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:19:47 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/19 16:25:41 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	up_move(t_data *data)
{
	double	vpdx;
	double	vpdy;
	// printf("vpdx : %f\tvpdy : %f\n", vpdx, vpdy);
	// printf("pdx : %f\tvdy : %f\n", data->player.pdx, data->player.pdy);
	data->player.pos_x -= data->player.pdx * 1.4;
	data->player.pos_y -= data->player.pdy * 1.4;
	// data->player.pos_y -=5;
}

void	down_move(t_data *data)
{
	double	vpdx;
	double	vpdy;

	// vpdx = velocity_coeff(d_abs(data->player.pdx));
	// vpdy = velocity_coeff(d_abs(data->player.pdy));

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

	angle = data->player.p_a  * PI / 180.0;
	perpendicular_angle = angle - PI / 2.0;
	perpendicularx = cos(perpendicular_angle);
	perpendiculary = sin(perpendicular_angle);
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

	angle = data->player.p_a  * PI / 180.0;
	perpendicular_angle = angle + PI / 2.0;
	perpendicularx = cos(perpendicular_angle);
	perpendiculary = sin(perpendicular_angle);
	magnitude = sqrt(perpendicularx * perpendicularx + perpendiculary * perpendiculary);
	perpendicularx /= magnitude;
	perpendiculary /= magnitude;
	data->player.pos_x += 1.4 * perpendicularx;
	data->player.pos_y += 1.4 * perpendiculary;
}
