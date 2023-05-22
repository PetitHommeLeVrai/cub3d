/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:43:12 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/22 17:00:33 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//render
int	draw(t_data *data)
{
	return (1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length + x * 4);
	*(unsigned int *)dst = color;
}

int	destroy_win(t_data *data)
{
	mlx_destroy_window(data->img.mlx_ptr, data->img.win_ptr);
	mlx_destroy_display(data->img.mlx_ptr);
	free(data->img.mlx_ptr);
	free(data->img.n_path);
	free(data->img.s_path);
	free(data->img.w_path);
	free(data->img.e_path);
	free(data->img.c_color);
	free(data->img.f_color);
	exit(0);
}
