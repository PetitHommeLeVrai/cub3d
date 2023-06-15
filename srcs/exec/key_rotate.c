/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:20:42 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/15 21:05:24 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rray_rotate(t_data *data)
{
	data->player.p_a -= 3.0f;
	printf("pa : %f\n", data->player.p_a);
	// if (data->player.p_a <  0)
	// 	data->player.p_a += 2 * PI;
	data->player.pdx = cos(degToRad(data->player.p_a)) * 5;
	data->player.pdy = sin(degToRad(data->player.p_a)) * 5;
}

void	lray_rotate(t_data *data)
{
	data->player.p_a += 3.0f;
	printf("pa : %f\n", data->player.p_a);
	// if (data->player.p_a > 2 * PI)
	// {
	// 	data->player.p_a -= 2 * PI;
	// }
	data->player.pdy = sin(degToRad(data->player.p_a)) * 5;
	data->player.pdx = cos(degToRad(data->player.p_a)) * 5;
}
