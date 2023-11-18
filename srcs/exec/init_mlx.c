/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:49:56 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/07/20 14:46:19 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_data *data)
{
	data->img.mlx_ptr = mlx_init();
	if (!data->img.mlx_ptr)
		return (free_map(data), exit_error(E_MLX));
	data->img.img_ptr = mlx_new_image(data->img.mlx_ptr, WIDTH, HEIGHT);
	if (!data->img.img_ptr)
		return (free_map(data), exit_error(E_MLX));
	data->img.addr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
	if (!data->img.addr)
		return (free_map(data), exit_error(E_MLX));
}

void	init_mlx2(t_data *data)
{
	int	tex_h;
	int	tex_w;

	tex_h = 64;
	tex_w = 64;
	data->img.win2_ptr = mlx_new_window(data->img.mlx_ptr, WIDTH, HEIGHT,
			"./cub3d");
	data->img.img2_ptr = mlx_new_image(data->img.mlx_ptr, WIDTH, HEIGHT);
	data->img.addr2 = mlx_get_data_addr(data->img.img2_ptr,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
	data->txt.img_north = mlx_xpm_file_to_image(data->img.mlx_ptr,
			data->img.n_path, &tex_h, &tex_w);
	data->txt.img_south = mlx_xpm_file_to_image(data->img.mlx_ptr,
			data->img.s_path, &tex_h, &tex_w);
	data->txt.img_east = mlx_xpm_file_to_image(data->img.mlx_ptr,
			data->img.e_path, &tex_h, &tex_w);
	data->txt.img_west = mlx_xpm_file_to_image(data->img.mlx_ptr,
			data->img.w_path, &tex_h, &tex_w);
	mlx_key_hook(data->img.win2_ptr, move_key_hook, data);
	mlx_hook(data->img.win2_ptr, 33, 0, &destroy_win, data);
	mlx_hook(data->img.win2_ptr, KeyPress, KeyPressMask, &handle_input, data);
}
