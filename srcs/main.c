/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:28:56 by aboyer            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/22 13:54:01 by mmeguedm         ###   ########.fr       */
=======
/*   Updated: 2023/05/22 14:38:06 by aboyer           ###   ########.fr       */
>>>>>>> ba8dfd3cea77f17663ede36f491d0d04e8220a7d
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

<<<<<<< HEAD
	init(&data, ac, av);
=======
	if (ac != 2)
	{
		printf("Error\nOnly 1 argument is needed\n");
		return (1);
	}
	parse_main(av[1], &data);
	if (init(&data, ac, av) == 0)
		return (1);
>>>>>>> ba8dfd3cea77f17663ede36f491d0d04e8220a7d
}
