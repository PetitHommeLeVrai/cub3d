/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:16:10 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/19 17:37:54 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*	<main_parsing.c>  */
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
int		get_player_pos(t_data *data, char **map);
int		get_map_last_line(char **map);
int		get_bigger_len(char **map);

/*	<parse_colors.c>  */
void	free_split_rgb(char **rgb);
void	isnumber(char **rgb, char *str, t_data *data);
void	check_colors(t_data *data);
void	fill_colors(t_data *data);

/*	<parse_textures.c>  */
void	get_textures(t_data *data);
void	set_path(t_data *data, char *key, char *path);
void	check_path_textures(t_data *data);
char	**init_var(t_data *data);

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
int		is_wspace(char c);
int		only_wspace(char *str);
int		FixAng(int a);
#endif
