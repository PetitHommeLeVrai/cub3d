/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:28:56 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/18 15:19:23 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "./cub3d");
	if (!data->win_ptr)
		return (0);
	return(1);
}

int draw(t_data *data)
{
	//render 3d
	return (1);
}

int destroy_win(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	handle_input(int keysym, t_data *data)
{
	return (1);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		destroy_win(data);
	return (1);
}

void init_hook(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &draw, data);
	mlx_hook(data->win_ptr, 33, 0, &destroy_win, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_input, data);
	mlx_hook(data->win_ptr, KeyRelease, 1L << 1, &handle_keyrelease, data);
	mlx_loop(data->mlx_ptr);
	destroy_win(data);
}

int init(t_data *data, int ac, char **av)
{
	if (init_mlx(data) == 0)
	{
		printf("Error\nSomething went wrong initializing mlx\n");
		return(0);
	}
	init_hook(data);
}

int main(int ac, char **av)
{
	t_data data;

	if (ac != 2)
	{
		printf("Error\nOnly 1 argument is needed\n");
		return (1);
	}
	if (init(&data, ac, av) == 0)
		return (1);
}
