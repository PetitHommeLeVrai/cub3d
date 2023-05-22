/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:14:26 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/22 17:00:55 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	free(data->img.n_path);
	free(data->img.s_path);
	free(data->img.e_path);
	free(data->img.w_path);
	free(data->img.c_color);
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

void	set_path(t_data *data, char *key, char *path)
{
	if (!key)
		return ;
	if (ft_strncmp("NO", key, 2) == 0)
		data->img.n_path = ft_strdup(path);
	if (ft_strncmp("SO", key, 2) == 0)
		data->img.s_path = ft_strdup(path);
	if (ft_strncmp("WE", key, 2) == 0)
		data->img.w_path = ft_strdup(path);
	if (ft_strncmp("EA", key, 2) == 0)
		data->img.e_path = ft_strdup(path);
	if (ft_strncmp("F ", key, 2) == 0)
		data->img.f_color = ft_strdup(path);
	if (ft_strncmp("C ", key, 2) == 0)
		data->img.c_color = ft_strdup(path);
}

static char	**init_key(void)
{
	static char	*key[] = {
		"NO",
		"SO",
		"WE",
		"EA",
		"F ",
		"C "};

	return (key);
}

void	get_textures(t_data *data)
{
	int					i;
	int					j;
	static char			**key;
	int					k;

	key = init_key();
	i = 0;
	while (data->img.map[i])
	{
		k = 0;
		j = 0;
		while (key[j])
		{
			if (ft_strncmp(data->img.map[i], key[j], 2) == 0)
			{
				while (data->img.map[i][k] && data->img.map[i][k] != ' ')
					k++;
				while (data->img.map[i][k] && data->img.map[i][k] == ' ')
					k++;
				set_path(data, key[j], data->img.map[i] + k);
			}
			j++;
		}
		i++;
	}
}

void	parse_main(int ac, char *file, t_data *data)
{
	if (ac != 2)
		exit_error(E_ARG);
	if (!file)
		exit_error(E_ACCESS);
	check_file(file);
	init_ftc(file, data);
	get_textures(data);
}
