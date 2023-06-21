/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:54:44 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/21 19:50:03 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

#include "tools.h"

void	raycasting(t_data *data);
void	rotate_line(t_data *data);
void	start_pos_to_rad(t_data *data);
void	draw_line_with_coord(t_data *data, int x1, int y1, int x2, int y2);
void	draw_wall(t_data *data, double ray_dist, int x);


/*	<utils_maths.c>  */
void	convert_map_to_int(t_data *data);
int		get_surface_map(t_data *data);
int		FixAng(int a);
float	distance(float ax, float ay, float bx, float by, float ang);
float	degToRad(int a);

#endif
