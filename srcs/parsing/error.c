/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:56:10 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/05/31 16:52:08 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(int err_msg)
{
	const char	*map_error[E_LENGHT] = {
		"The requested access to the file is prohibited, \
		or the file does not yet exist.\n",
		"Invalid file extension (.cub required).\n",
		"Only 1 argument is required.\n",
		"Something went wrong initializing mlx.\n",
		"It seems like some textures or colors are missing.\n",
		"Invalid type of element.\n",
		"Color syntax is invalid.\n",
		"Color value not allowed.\n",
		"Out  of  memory.\n",
		"Given map is invalid.\n"
	};

	ft_putstr_fd("Error\n", STDOUT_FILENO);
	ft_putstr_fd((char *)map_error[err_msg], STDOUT_FILENO);
	exit(err_msg + 1);
}
