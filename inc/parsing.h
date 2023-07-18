/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:16:10 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/07/18 17:53:49 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*	<main_parsing.c>  */
void	init_mlx2(t_data *data);
void	init_mlx(t_data *data);
void	check_file(char *file);
void	main_parsing(int ac, char *file, t_data *data);
void	init_data(t_data *data);

/*	<parse_ftc.c>  */
void	free_map(t_data *data);
void	ftc_allocator(char *file, t_data *data);
void	init_ftc(char *file, t_data *data);

/*	<parse_map.c>  */
void	check_first_and_last_line(t_data *data, char **map);
void	is_map_surrouded_by_wall(t_data *data, char **map);
void	create_map_copy(t_data *data, char **map);
void	dfs(t_data *data, char **map, int y, int x);
void	check_map(t_data *data, char **map);

/*	<get.c>  */
int		get_pos(t_data *data, char **map);
int		get_player_pos(t_data *data, char **map);
int		get_map_last_line(char **map);
int		get_bigger_len(char **map);

void	fill_colors(t_data *data);

/*	<error.c>  */
void	exit_error(int err_msg);

/*	<get_map.c>  */
void	get_map(t_data *data);
void	get_position_player(t_data *data);
int		get_longest_line(char **file);
int		get_size_map(char **file);
void	get_position_player(t_data *data);

/*	<get_texture.c>  */
void	get_textures(t_data *data);

/*	<get_colors.c>  */
void	get_colors(t_data *data);

/*	<utils.c>  */
void	free_split_rgb(char **rgb);
bool	str_isnumber(char *str);
int		is_wspace(char c);
int		only_wspace(char *str);

/*	<init_geo.c>  */
char	init_coord(t_data *data, char **map, int x, int y);
void	init_north(t_data *data);
void	init_south(t_data *data);
void	init_west(t_data *data);
void	init_east(t_data *data);

#endif
