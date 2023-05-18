/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:14:26 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/18 14:49:12 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nFile does not exist\n");
		return (0);
	}
	close(fd);
	if (!ft_strnstr(file + (ft_strlen(file) - 4), ".cub"), 4)
	{
		printf("Error\nInvalid map extension (.cub required)\n");
		return (0);
	}
	return (1);
}

int	parse_main(char *file)
{
	if (!file)
	{
		printf("Error\nGiven File is Null\n");
		return (0);
	}
	if (check_file(file) == 0)
		return (0);
}
