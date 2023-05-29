/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:14:26 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/29 15:18:37 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_paths_to_null(t_data *data)
{
	data->img.n_path = NULL;
	data->img.s_path = NULL;
	data->img.e_path = NULL;
	data->img.w_path = NULL;
	data->img.c_color = NULL;
	data->img.f_color = NULL;
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

void	get_player_pos(t_data *data, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W' )
			{
				data->player.p_x = x;
				data->player.p_y = y;
				break ;
			}
			x++;
		}
		y++;
		x = 0;
	}
}

int get_map_last_line(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void check_first_and_last_line(t_data *data, char **map)
{
	int i;
	int x;

	x = 0;
	while (map[0][x])
	{
		if (map[0][x] != ' ' || map[0][x] != '1')
		{
			free_map(data);
			exit_error(E_IMAP);
		}
		x++;
	}
	x = 0;
	i = get_map_last_line(map);
	while (map[i][x])
	{
		if (map[0][x] != ' ' || map[0][x] != '1')
		{
			free_map(data);
			exit_error(E_IMAP);
		}
		x++;
	}
}


void is_map_surrouded_by_wall(t_data *data, char **map)
{
	int i;
	int len;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (map[i][len] == '\n')
			len -= 1;
		if (map[i][0] != ' ' || map[i][0] != '1' || map[i][len] != '1' || map[i][len] != ' ')
		{
			free_map(data);
			exit_error(E_IMAP);
		}
		i++;
	}
	check_first_and_last_line(data, map);
}

int get_bigger_len(char **map)
{
	int y;
	int x;
	int bigger;

	y = 0;
	bigger = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
			x++;
		if (x > bigger)
			bigger = x;
		y++;
	}
	return (bigger);
}

void create_map_copy(t_data *data, char **map)
{
	int x;
	int y;
	int i;

	x = get_bigger_len(map);
	data->img.map_cp = (char **)malloc(sizeof(char *) * (get_map_last_line(map) + 1));
	if (!data->img.map_cp)
		return (free_map(data), exit_error(E_IMAP));
	data->img.map_cp[get_map_last_line(map)] = NULL;
	y = 0;
	while(data->img.map_cp[y++])
	{
		i = ft_strlen(map[y]);
		data->img.map_cp[y] = (char *)malloc(sizeof(char *) * (x + 1));
			if (!data->img.map_cp[y])
				return (free_map(data), exit_error(E_IMAP));
		ft_strlcpy(data->img.map_cp[y], map[y], ft_strlen(map[y]));
		if (i < x)
		{
			while (i++ < x)
				data->img.map_cp[y][i] = ' ';
		}
	}
}

void dfs(t_data *data, char **map, int y, int x)
{
	if (map[y][x] != '0' || map[y][x] != 'N' || map[y][x] != 'S' || map[y][x] != 'W' || map[y][x] != 'E')
		return (free_map(data), exit_error(E_IMAP));
	map[y][x] = '1';
	if (map[y + 1][x] != '1')
		dfs(data, map, y + 1, x);
	if (map[y - 1][x] != '1')
		dfs(data, map, y - 1, x);
	if (map[y][x + 1] != '1')
		dfs(data, map, y, x + 1);
	if (map[y][x - 1] != '1')
		dfs(data, map, y, x - 1);
}

void check_map(t_data *data, char **map)
{
	int i;
	int j;
	int player_exist;

	i = 0;
	player_exist = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
				player_exist += 1;
			else if (map[i][j] != '0' || map[i][j] != '1' || map[i][j] != ' ' || map[i][j] != '\n')
				return (free_map(data), exit_error(E_IMAP));
			j++;
		}
		i++;
	}
	if (player_exist != 1)
		return (free_map(data), exit_error(E_IMAP));
	is_map_surrouded_by_wall(data, map);
	create_map_copy(data, map);
	get_player_pos(data, map);
	dfs(data, map, data->player.p_y, data->player.p_x);
}


void	parse_main(int ac, char *file, t_data *data)
{
	if (ac != 2)
		exit_error(E_ARG);
	if (!file)
		exit_error(E_ACCESS);
	check_file(file);
	init_ftc(file, data);
	init_paths_to_null(data);
	get_textures(data);
	check_textures(data);
	check_colors(data);
}
