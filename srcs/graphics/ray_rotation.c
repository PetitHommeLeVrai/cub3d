/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:03:16 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/14 20:04:54 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rray_rotate(t_data *data)
{
	data->player.p_a += 1.0f;
}

void	lray_rotate(t_data *data)
{
	data->player.p_a -= 1.0f;
}