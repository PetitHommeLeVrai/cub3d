/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:56:10 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/05/22 14:04:46 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(int err_msg)
{
	const char *map_error[E_LENGHT] = {
		"The requested access to the file is prohibited, or the file does not yet exist.\n",
		"Invalid map extension (.cub required).\n",
		"Only 1 argument is required.\n",
		"Something went wrong initializing mlx.\n"
	};
	
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	ft_putstr_fd((char *)map_error[err_msg], STDOUT_FILENO);
	exit(err_msg);
}