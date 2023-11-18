/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:43:06 by aboyer            #+#    #+#             */
/*   Updated: 2023/07/18 19:08:08 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_input(int keysym, t_data *data)
{
	(void)keysym;
	(void)data;
	return (1);
}

static	t_movement	*create_move_storage(void)
{
	static t_movement	move_storage[] = {
	{KEY_W, up_move},
	{KEY_S, down_move},
	{KEY_A, left_move},
	{KEY_D, right_move},
	{KEY_RIGHT, r_rotate},
	{KEY_LEFT, l_rotate},
	{KEY_ESC, destroy_win2},
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
	raycasting(data);
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.win2_ptr,
		data->img.img2_ptr, 0, 0);
	return (21);
}
