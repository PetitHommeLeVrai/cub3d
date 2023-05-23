/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:43:09 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/23 18:59:02 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mlx(t_data *data)
{
	data->img.mlx_ptr = mlx_init();
	if (!data->img.mlx_ptr)
		return (exit_error(E_MLX));
	data->img.win_ptr = mlx_new_window(data->img.mlx_ptr, WIDTH, HEIGHT,
			"./cub3d");
	if (!data->img.win_ptr)
		return (exit_error(E_MLX));
	data->img.img_ptr = mlx_new_image(data->img.mlx_ptr, WIDTH, HEIGHT);
	if (!data->img.img_ptr)
		return (exit_error(E_MLX));
	data->img.addr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
	if (!data->img.addr)
		return (exit_error(E_MLX));
}

static void	init_hook(t_data *data)
{
	mlx_loop_hook(data->img.mlx_ptr, &draw, data);
	mlx_hook(data->img.win_ptr, 33, 0, &destroy_win, data);
	mlx_hook(data->img.win_ptr, KeyPress, KeyPressMask, &handle_input, data);
	mlx_hook(data->img.win_ptr, KeyRelease, 1L << 1, &handle_keyrelease, data);
	mlx_loop(data->img.mlx_ptr);
	destroy_win(data);
}

void	init(t_data *data, int ac, char **av)
{
	parse_main(ac, av[1], data);
	init_mlx(data);
	get_position_player(data);
	init_hook(data);
}
