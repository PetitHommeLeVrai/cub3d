/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:14:26 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/23 17:24:25 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->img.n_path = NULL;
	data->img.s_path = NULL;
	data->img.e_path = NULL;
	data->img.w_path = NULL;
	data->img.c_color = NULL;
	data->img.f_color = NULL;
	data->player.pos_x = 0;
	data->player.pos_y = 0;
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

void	parse_main(int ac, char *file, t_data *data)
{
	if (ac != 2)
		exit_error(E_ARG);
	if (!file)
		exit_error(E_ACCESS);
	check_file(file);
	init_ftc(file, data);
	init_data(data);
	get_textures(data);
	check_textures(data);
	check_colors(data);
}
