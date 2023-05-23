/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ftc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:07:16 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/23 13:57:46 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->img.map[i])
	{
		free(data->img.map[i]);
		i++;
	}
	free(data->img.map[i]);
	free(data->img.map);
	if (data->img.n_path)
		free(data->img.n_path);
	if (data->img.s_path)
		free(data->img.s_path);
	if (data->img.e_path)
		free(data->img.e_path);
	if (data->img.w_path)
		free(data->img.w_path);
	if (data->img.c_color)
		free(data->img.c_color);
	if (data->img.f_color)
		free(data->img.f_color);
}

void	ftc_allocator(char *file, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	data->img.map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!data->img.map)
		exit_error(E_ACCESS);
}

void	init_ftc(char *file, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	ftc_allocator(file, data);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		data->img.map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	data->img.map[i] = NULL;
	close(fd);
}
