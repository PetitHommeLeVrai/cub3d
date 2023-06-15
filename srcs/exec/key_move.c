/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:19:47 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/15 21:05:54 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float d_abs(float abs)
{
	printf("abs : %f\n", abs);
	if (abs < 0.0f)
		return (abs * (-1.0f));
	return (abs);
}

static double	velocity_coeff(int pdxy)
{
	return (5.0f / pdxy);
}

void	up_move(t_data *data)
{
	double	vpdx;
	double	vpdy;

	vpdx = velocity_coeff(d_abs(data->player.pdx));
	vpdy = velocity_coeff(d_abs(data->player.pdy));
	
	// printf("vpdx : %f\tvpdy : %f\n", vpdx, vpdy);
	printf("pdx : %f\tvdy : %f\n", data->player.pdx, data->player.pdy);
	data->player.pos_x += data->player.pdx * 1.4;
	data->player.pos_y += data->player.pdy * 1.4;
	// data->player.pos_y -=5;
}

void	down_move(t_data *data)
{
	data->player.pos_y += 5;
}

void	right_move(t_data *data)
{
	data->player.pos_x += 5;
}

void	left_move(t_data *data)
{
	data->player.pos_x -= 5;
}
