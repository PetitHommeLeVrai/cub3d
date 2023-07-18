/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:54:44 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/07/18 18:42:29 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "tools.h"

void	raycasting(t_data *data);
int		create_trgb(unsigned char t, unsigned char r,
			unsigned char g, unsigned char b);

/*	<calcul.c>  */
void	extra_draw_pixels(t_data *data, int x, double step);
void	calculate_side_distances(t_data *data);
void	calculate_line_height_and_draw_start_end(t_data *data);
void	calculate_wall_x(t_data *data, int side);
void	calculate_tex_x(t_data *data, int side);

#endif
