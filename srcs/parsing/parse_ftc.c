/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ftc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:07:16 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/30 17:07:59 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	data->img.file = (char **)malloc(sizeof(char *) * (i + 1));
	if (!data->img.file)
		exit_error(E_ACCESS);
}

static char	*rm_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = 0;
		i++;
	}
	return (str);
}

void	init_ftc(char *file, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	ftc_allocator(file, data);
	fd = open(file, O_RDONLY);
	line = rm_nl(get_next_line(fd));
	i = 0;
	while (line)
	{
		data->img.file[i] = line;
		line = rm_nl(get_next_line(fd));
		i++;
	}
	data->img.file[i] = NULL;
	close(fd);
}
