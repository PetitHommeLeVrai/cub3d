/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:43:06 by aboyer            #+#    #+#             */
/*   Updated: 2023/06/14 18:12:39 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_input(int keysym, t_data *data)
{
	(void)keysym;
	(void)data;
	return (1);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	(void)data;
	if (keysym == XK_Escape)
		destroy_win(data);
	return (1);
}

static void	free_mlx(t_data *data)
{
	mlx_destroy_window(data->img.mlx_ptr, data->img.win_ptr);
	mlx_destroy_image(data->img.mlx_ptr, data->img.img_ptr);
	mlx_destroy_display(data->img.mlx_ptr);
	free(data->img.mlx_ptr);
}

int	close_window_key_esc(t_data *data, double uncessary)
{
	(void)uncessary;
	free_mlx(data);
	exit(EXIT_SUCCESS);
	return (21);
}

static	t_movement	*create_move_storage(void)
{
	static t_movement	move_storage[] = {
	{KEY_UP, up_move},
	{KEY_DOWN, down_move},
	{KEY_LEFT, left_move},
	{KEY_RIGHT, right_move},
	{KEY_ESC, close_window_key_esc},
	{0, NULL},
	};

	return (move_storage);
}

int	move_key_hook(unsigned int keycode, t_data *data)
{
	static t_movement	*move_storage;

	move_storage = create_move_storage();
	while (move_storage->key_fp)
	{
		if (move_storage->key == keycode)
		{
			move_storage->key_fp(data);
			break ;
		}
		move_storage++;
	}
	draw_map(data);
	return (21);
}
