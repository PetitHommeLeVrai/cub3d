/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:43:09 by aboyer            #+#    #+#             */
/*   Updated: 2023/07/14 15:54:29 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_pos_to_rad(t_data *data)
{
	if (data->player.compass_point == 'N')
		data->player.p_a = 90;
	else if (data->player.compass_point == 'S')
		data->player.p_a = 270;
	else if (data->player.compass_point == 'W')
		data->player.p_a = 180;
	else if (data->player.compass_point == 'E')
		data->player.p_a = 0;
	data->player.pdx = cos(degToRad(data->player.p_a) * 5);
	data->player.pdy = sin(degToRad(data->player.p_a) * 5);
}

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

static void	init_mlx(t_data *data)
{
	data->img.mlx_ptr = mlx_init();
	if (!data->img.mlx_ptr)
		return (exit_error(E_MLX));
	data->img.win_ptr = mlx_new_window(data->img.mlx_ptr, WIDTH, HEIGHT,
			"./minimap");
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

static void	init_mlx2(t_data *data)
{
	int texH = 64;
	int texW = 64;
	data->img.win2_ptr = mlx_new_window(data->img.mlx_ptr, WIDTH, HEIGHT,
		"./cub3d");
	data->img.img2_ptr = mlx_new_image(data->img.mlx_ptr, WIDTH, HEIGHT);
	data->img.addr2 = mlx_get_data_addr(data->img.img2_ptr,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
	data->txt.img_north = mlx_xpm_file_to_image(data->img.mlx_ptr, data->img.n_path, &texH, &texW);
	data->txt.img_south = mlx_xpm_file_to_image(data->img.mlx_ptr, data->img.s_path, &texH, &texW);
	data->txt.img_east = mlx_xpm_file_to_image(data->img.mlx_ptr, data->img.e_path, &texH, &texW);
	data->txt.img_west = mlx_xpm_file_to_image(data->img.mlx_ptr, data->img.w_path, &texH, &texW);
	mlx_key_hook(data->img.win2_ptr, move_key_hook, data);
	mlx_hook(data->img.win2_ptr, 33, 0, &destroy_win, data);
	mlx_hook(data->img.win2_ptr, KeyPress, KeyPressMask, &handle_input, data);
}

static void	init_hook(t_data *data)
{
	mlx_loop_hook(data->img.mlx_ptr, &draw, data);
	mlx_hook(data->img.win_ptr, 33, 0, &destroy_win, data);
	mlx_hook(data->img.win_ptr, KeyPress, KeyPressMask, &handle_input, data);
	// mlx_hook(data->img.win_ptr, KeyRelease, 1L << 1, &handle_keyrelease, data);
	mlx_key_hook(data->img.win_ptr, move_key_hook, data);
}

void	init(t_data *data, int ac, char **av)
{
	main_parsing(ac, av[1], data);
	init_mlx(data);
	init_mlx2(data);
	init_hook(data);
}
