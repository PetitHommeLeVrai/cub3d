/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:49:56 by aboyer            #+#    #+#             */
/*   Updated: 2023/06/15 19:35:39 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "tools.h"

void	init(t_data *data, int ac, char **av);
int		destroy_win(t_data *data);
int		draw(t_data *data);
int		handle_keyrelease(int keysym, t_data *data);
int		handle_input(int keysym, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);
void	draw_map(t_data *data);
int		move_key_hook(unsigned int keycode, t_data *data);
void	get_cell_dim(t_data *data);

/*	Handle key_hook		*/
/*		<key_rotate.c>  */
void	rray_rotate(t_data *data);
void	lray_rotate(t_data *data);
/*		<move.c>		*/
void	up_move(t_data *data);
void	down_move(t_data *data);
void	right_move(t_data *data);
void	left_move(t_data *data);

float degToRad(int a);

#endif
