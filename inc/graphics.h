/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:54:44 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/07/18 00:29:03 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

#include "tools.h"

void	raycasting(t_data *data);
void	rotate_line(t_data *data);
void	start_pos_to_rad(t_data *data);
void	draw_line_with_coord(t_data *data, int x1, int y1, int x2, int y2, int color);
void	draw_wall(t_data *data, double ray_dist, int x, int hit_x, int hit_y);
void	draw_color(t_data *data, int ray_a);
int		create_trgb(unsigned char t, unsigned char r, unsigned char  g, unsigned char b);

/*	<utils_maths.c>  */
void	convert_map_to_int(t_data *data);
int		get_surface_map(t_data *data);
int		FixAng(int a);
float	distance(float ax, float ay, float bx, float by, float ang);
float	degToRad(int a);

/*	<calcul.c>  */
void	extra_draw_pixels(t_data *data, int x, double step);
void    calculate_side_distances(t_data *data);
void	calculate_line_height_and_draw_start_end(t_data *data);
void	calculate_wall_x(t_data *data, int side);
void	calculate_tex_x(t_data *data, int side);

#endif
