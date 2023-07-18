/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:28:56 by aboyer            #+#    #+#             */
/*   Updated: 2023/07/18 18:03:33 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	init(&data, ac, av);
	data.player.pos_x += data.player.case_width - 10;
	data.player.pos_y += data.player.case_height - 100;
	get_pos(&data, data.img.map);
	raycasting(&data);
	mlx_loop(data.img.mlx_ptr);
}
