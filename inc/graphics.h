/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:54:44 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/14 17:35:17 by mmeguedm         ###   ########.fr       */
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

#endif
