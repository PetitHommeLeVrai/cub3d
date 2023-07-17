/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:43:09 by aboyer            #+#    #+#             */
/*   Updated: 2023/07/17 23:21:33 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->img.n_path = NULL;
	data->img.s_path = NULL;
	data->img.e_path = NULL;
	data->img.w_path = NULL;
	data->img.c_color = NULL;
	data->img.f_color = NULL;
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	data->txt.count = 0;
	data->txt.index_file = 0;
	data->img.map = NULL;
	data->img.file = NULL;
	data->img.map_cp = NULL;
}

static void	init_hook(t_data *data)
{
	mlx_hook(data->img.win_ptr, 33, 0, &destroy_win, data);
	mlx_hook(data->img.win_ptr, KeyPress, KeyPressMask, &handle_input, data);
	mlx_key_hook(data->img.win_ptr, move_key_hook, data);
}

void	init(t_data *data, int ac, char **av)
{
	main_parsing(ac, av[1], data);
	init_mlx(data);
	init_mlx2(data);
	init_hook(data);
}
