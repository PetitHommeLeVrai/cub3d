/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:14:26 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/22 16:21:29 by aboyer           ###   ########.fr       */
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
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map[i]);
	free(data->map);
	free(data->n_path);
	free(data->s_path);
	free(data->e_path);
	free(data->w_path);
	free(data->c_color);
	free(data->f_color);
}

void	map_allocator(char *file, t_data *data)
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
	data->map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!data->map)
		exit_error(E_ACCESS);
}

void	init_map(char *file, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	map_allocator(file, data);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		data->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
	close(fd);
}

void	set_path(t_data *data, char *key, char *path)
{
	if (!key)
		return ;
	if (ft_strncmp("NO", key, 2))
		data->n_path = ft_strdup(path);
	if (ft_strncmp("SO", key, 2))
		data->s_path = ft_strdup(path);
	if (ft_strncmp("WE", key, 2))
		data->w_path = ft_strdup(path);
	if (ft_strncmp("EA", key, 2))
		data->e_path = ft_strdup(path);
	if (ft_strncmp("F ", key, 2))
		data->f_color = ft_strdup(path);
	if (ft_strncmp("C ", key, 2))
		data->c_color = ft_strdup(path);
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
	static char	**key;
	int					k;

	key = init_key();
	i = 0;
	j = 0;
	while (data->map[i])
	{
		k = 0;
		while (key[j])
		{
			if (ft_strncmp(data->map[i], key[j], 2))
			{
				while (data->map[i][k] && data->map[i][k] != ' ')
					k++;
				while (data->map[i][k] && data->map[i][k] == ' ')
					k++;
				set_path(data, key[j], data->map[i] + k);
			}
			j++;
		}
		i++;
	}
}

void	parse_main(char *file, t_data *data)
{
	if (!file)
		exit_error(E_ACCESS);
	check_file(file);
	init_map(file, data);
	get_textures(data);
	printf("%s\n", data->c_color);
}
