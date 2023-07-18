/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:14:26 by aboyer            #+#    #+#             */
/*   Updated: 2023/07/18 19:58:43 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_leak(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(E_ACCESS);
	close(fd);
	if (!(ft_strnstr(file + (ft_strlen(file) - 4), ".cub", 4)))
		exit_error(E_IMAP);
}

void	main_parsing(int ac, char *file, t_data *data)
{
	char	**map;

	if (ac != 2)
		exit_error(E_ARG);
	if (!file)
		exit_error(E_ACCESS);
	init_data(data);
	check_file(file);
	init_ftc(file, data);
	get_textures(data);
	get_colors(data);
	get_map(data);
	map = data->img.map;
	get_position_player(data);
	check_map(data, map);
	free_leak(map);
}
