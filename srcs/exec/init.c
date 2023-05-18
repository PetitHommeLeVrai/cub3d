/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:43:09 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/18 16:51:46 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "./cub3d");
	if (!data->win_ptr)
		return (0);
	return (1);
}

static void	init_hook(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &draw, data);
	mlx_hook(data->win_ptr, 33, 0, &destroy_win, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_input, data);
	mlx_hook(data->win_ptr, KeyRelease, 1L << 1, &handle_keyrelease, data);
	mlx_loop(data->mlx_ptr);
	destroy_win(data);
}

int	init(t_data *data, int ac, char **av)
{
	if (init_mlx(data) == 0)
	{
		printf("Error\nSomething went wrong initializing mlx\n");
		return (0);
	}
	init_hook(data);
}
