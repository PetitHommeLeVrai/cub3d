/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:54:44 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/14 20:04:52 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

#include "tools.h"

void	raycasting(t_data *data);

/*	<move.c>  */
void	up_move(t_data *data);
void	down_move(t_data *data);
void	right_move(t_data *data);
void	left_move(t_data *data);

/*	<ray_rotation.c>  */
void	rray_rotate(t_data *data);
void	lray_rotate(t_data *data);

#endif
