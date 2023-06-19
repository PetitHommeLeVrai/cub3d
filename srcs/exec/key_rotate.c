/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:20:42 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/19 17:49:52 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	r_rotate(t_data *data)
{
	data->player.p_a -= 3.0f;
	data->player.p_a = FixAng(data->player.p_a);
	data->player.pdx = -cos(degToRad(data->player.p_a)) * 5;
	data->player.pdy = sin(degToRad(data->player.p_a)) * 5;
}

void	l_rotate(t_data *data)
{
	data->player.p_a += 3.0f;
	data->player.p_a = FixAng(data->player.p_a);
	data->player.pdx = -cos(degToRad(data->player.p_a)) * 5;
	data->player.pdy = sin(degToRad(data->player.p_a)) * 5;
}
