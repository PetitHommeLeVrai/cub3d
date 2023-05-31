/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:11:28 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/31 15:42:14 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_first_and_last_line(t_data *data, char **map)
{
	int	i;
	int	x;

	x = 0;
	while (map[0][x])
	{
		if (map[0][x] != ' ' && map[0][x] != '1')
			return (free_map(data), exit_error(E_IMAP));
		x++;
	}
	x = 0;
	i = get_map_last_line(map) - 1;
	while (map[i][x])
	{
		if (map[0][x] != ' ' && map[0][x] != '1')
			return (free_map(data), exit_error(E_IMAP));
		x++;
	}
}

void	is_map_surrouded_by_wall(t_data *data, char **map)
{
	int	i;
	int	len;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (map[i][len] == '\n')
			len -= 1;
		if (map[i][0] != ' ' && map[i][0] != '1' && map[i][len] != '1'
			&& map[i][len] != ' ')
			return (free_map(data), exit_error(E_IMAP));
		i++;
	}
	check_first_and_last_line(data, map);
}

void	create_map_copy(t_data *data, char **map)
{
	int	x;
	int	y;
	int	i;

	x = get_bigger_len(map);
	data->img.map_cp = malloc(sizeof(char *) * (get_map_last_line(map) + 1));
	if (!data->img.map_cp)
		return (free_map(data), exit_error(E_IMAP));
	y = 0;
	while (data->img.map[y])
	{
		i = ft_strlen(map[y]);
		data->img.map_cp[y] = (char *)malloc(sizeof(char *) * (x + 1));
		if (!data->img.map_cp[y])
			return (free_map(data), exit_error(E_IMAP));
		ft_strlcpy(data->img.map_cp[y], map[y], ft_strlen(map[y]) + 1);
		if (i < x)
		{
			while (i < x)
				data->img.map_cp[y][i++] = ' ';
			data->img.map_cp[y][i] = 0;
		}
		y++;
	}
	data->img.map_cp[y] = 0;
}

void	dfs(t_data *data, char **map, int y, int x)
{
	if (map[y][x] != '0' && map[y][x] != 'N' && map[y][x] != 'S'
		&& map[y][x] != 'W' && map[y][x] != 'E')
		return (free_map(data), exit_error(E_MAP));
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

void	check_map(t_data *data, char **map)
{
	int	i;
	int	j;
	int	player_exist;

	i = -1;
	player_exist = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				player_exist += 1;
			else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' '
					&& map[i][j] != '\n')
				return (free_map(data), exit_error(E_IMAP));
		}
	}
	if (player_exist != 1)
		return (free_map(data), exit_error(E_IMAP));
	is_map_surrouded_by_wall(data, map);
	create_map_copy(data, map);
	get_player_pos(data, map);
	dfs(data, data->img.map_cp, data->player.p_y, data->player.p_x);
}
