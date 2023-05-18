/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:28:56 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/18 14:34:29 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main(int ac, char **av)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "./cub3d");
	if (!data.win_ptr)
		return (0);
}
