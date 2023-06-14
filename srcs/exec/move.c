/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:30:37 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/14 19:23:19 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	up_move(t_data *data)
{
	data->player.pos_y--;
}

void	down_move(t_data *data)
{
	data->player.pos_y++;
}

void	right_move(t_data *data)
{
	data->player.p_a += 1.0f;
	data->player.pos_x++;
}

void	left_move(t_data *data)
{
	data->player.p_a -= 1.0f;
	data->player.pos_x--;
}
