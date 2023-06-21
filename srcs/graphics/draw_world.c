/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:27:47 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/21 19:32:21 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	draw_wall(t_data *data, double ray_dist, int x)
{
	int wall_height;
	int wall_top;
	int wall_bottom;
	int y;

	y = 0;
	wall_height = (int)((HEIGHT * 22) / (ray_dist));
	wall_top = (HEIGHT - wall_height) / 2;
	wall_bottom = wall_top + wall_height;
	while (y < wall_top)
	{
		// Dessiner le ciel
		my_mlx_pixel_put2(data, x, y, BLUE);
		y++;
	}
	while (y >= wall_top && y <= wall_bottom)
	{
		// Dessiner le mur
		my_mlx_pixel_put2(data, x, y, GREEN);
		y++;
	}
	while (y < HEIGHT)
	{
		// Dessiner le sol
		my_mlx_pixel_put2(data, x, y, YELLOW);
		y++;
	}
}
