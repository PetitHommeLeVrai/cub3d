/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:16:10 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/05/30 14:19:11 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*	<parse_main.c>  */
void	check_file(char *file);
void	parse_main(int ac, char *file, t_data *data);
void	init_paths_to_null(t_data *data);

/*	<parse_ftc.c>  */
void	free_map(t_data *data);
void	ftc_allocator(char *file, t_data *data);
void	init_ftc(char *file, t_data *data);

/*	<parse_colors.c>  */
void	free_split_rgb(char **rgb);
void	isnumber(char **rgb, char *str, t_data *data);
void	check_colors(t_data *data);

/*	<parse_map.c>  */
void	check_map(t_data *data, char **map);
void	dfs(t_data *data, char **map, int y, int x);
void	create_map_copy(t_data *data, char **map);
void	is_map_surrouded_by_wall(t_data *data, char **map);
void	check_first_and_last_line(t_data *data, char **map);

/*	get.c>  */
int		get_bigger_len(char **map);
int		get_map_last_line(char **map);
void	get_player_pos(t_data *data, char **map);

/*	<parse_textures.c>  */
void	get_textures(t_data *data);
void	set_path(t_data *data, char *key, char *path);
void	check_textures(t_data *data);
char	**init_var(t_data *data);

/*	<error.c>  */
void	exit_error(int err_msg);

#endif
