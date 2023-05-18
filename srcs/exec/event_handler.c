/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:43:06 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/18 17:42:20 by aboyer           ###   ########.fr       */
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
