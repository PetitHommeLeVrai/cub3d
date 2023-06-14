/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:30:37 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/14 18:04:07 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	up_move(t_data *data)
{
	printf("Test\n");
	data->player.pos_y--;
}

void	down_move(t_data *data)
{
	data->player.pos_y++;
}

void	right_move(t_data *data)
{
	data->player.pos_x++;
}

void	left_move(t_data *data)
{
	data->player.pos_x--;
}