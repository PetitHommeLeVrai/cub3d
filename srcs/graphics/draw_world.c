/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:27:47 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/06/22 18:32:00 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	draw_wall(t_data *data, double ray_dist, int x)
{
	int wall_height;
	int wall_top;
	int wall_bottom;
	int y;
	int stop;

	stop = x;
	wall_height = (int)((HEIGHT * 15) / (ray_dist));
	wall_top = (HEIGHT - wall_height) / 2;
	if (wall_top <= 0)
		wall_top = 0;
	wall_bottom = wall_top + wall_height;
	if (wall_bottom >= HEIGHT)
		wall_bottom = HEIGHT - 1;
	while (x < stop + 10)
	{
		y = 0;
		while (y < wall_top)
		{
			my_mlx_pixel_put2(data, x, y, BLUE);
			y++;
		}
		while (y >= wall_top && y <= wall_bottom)
		{
			my_mlx_pixel_put2(data, x, y, GREEN);
			y++;
		}
		while (y < HEIGHT)
		{
			my_mlx_pixel_put2(data, x, y, YELLOW);
			y++;
		}
		x++;
	}
}
