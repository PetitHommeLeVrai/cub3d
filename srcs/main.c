/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:28:56 by aboyer            #+#    #+#             */
/*   Updated: 2023/07/18 20:02:37 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	init(&data, ac, av);
	get_pos(&data, data.img.map);
	data.player.pos_x += 0.5;
	data.player.pos_y += 0.5;
	raycasting(&data);
	mlx_loop(data.img.mlx_ptr);
}
