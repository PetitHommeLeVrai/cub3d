/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:28:56 by aboyer            #+#    #+#             */
/*   Updated: 2023/07/18 17:21:47 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	init(&data, ac, av);
	get_cell_dim(&data);
	data.player.pos_x += data.player.case_width - 10;
	data.player.pos_y += data.player.case_height - 100;
	get_pos(&data, data.img.map);
	draw_map(&data);
	mlx_loop(data.img.mlx_ptr);
}
