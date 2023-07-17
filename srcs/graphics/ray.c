/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:34:01 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/07/17 17:14:43 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64

void raycasting(t_data *data)
{
	int bpp;
	int size_line;
	int endian;
  int *pixels;
	double posX = data->player.pos_y, posY = data->player.pos_x;  //x and y start position
	double dirX = data->ray.dirx, dirY = data->ray.diry; //initial direction vector
	double planeX = data->ray.planex, planeY = data->ray.planey; //the 2d raycaster version of camera plane

  //start the main loop
    for(int x = 0; x < screenWidth ; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)screenWidth  - 1; //x-coordinate in camera space
      double rayDirX = dirX + planeX*cameraX;
      double rayDirY = dirY + planeY*cameraX;

      //which box of the map we're in
      int mapX = (int)posX;
      int mapY = (int)posY;

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

      //length of ray from one x or y-side to next x or y-side
      double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
      double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?

      //calculate step and initial sideDist
      if(rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if(sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if(data->img.map[mapX][mapY] == '1') hit = 1;
      }

      if (rayDirY >= 0.0  && side == 1)
        pixels = (int *)mlx_get_data_addr(data->txt.img_east, &bpp, &size_line, &endian);
      else if (rayDirY <= 0.0  && side == 1)
	      pixels = (int *)mlx_get_data_addr(data->txt.img_west, &bpp, &size_line, &endian);
      else if (rayDirX <= 0.0  && side == 0)
        pixels = (int *)mlx_get_data_addr(data->txt.img_north, &bpp, &size_line, &endian);
      else
        pixels = (int *)mlx_get_data_addr(data->txt.img_south, &bpp, &size_line, &endian);

      //Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);

      //Calculate height of line to draw on screen
      int lineHeight = (int)(screenHeight  / perpWallDist);


      int pitch = 100;

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + screenHeight  / 2 + pitch;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + screenHeight  / 2 + pitch;
      if(drawEnd >= screenHeight ) drawEnd = screenHeight  - 1;

      //calculate value of wallX
      double wallX; //where exactly the wall was hit
      if(side == 0) wallX = posY + perpWallDist * rayDirY;
      else          wallX = posX + perpWallDist * rayDirX;
      wallX -= floor((wallX));

      //x coordinate on the texture
      int texX = (int)(wallX * (double)(texWidth));
      if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
      if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;

      // TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
      // How much to increase the texture coordinate per screen pixel
      double step = 1.0 * texHeight / lineHeight;
      // Starting texture coordinate
      double texPos = (drawStart - pitch - screenHeight  / 2 + lineHeight / 2) * step;
      for(int g = 0; g < drawStart; g++)
      {
          if (g < screenHeight)
            my_mlx_pixel_put2(data, x, g, data->txt.c_color);
      }
      for(int y = drawStart; y < drawEnd; y++)
      {
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        int texY = (int)texPos & (texHeight - 1);
        texPos += step;
        int color = pixels[texHeight * texY + texX];
        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		    my_mlx_pixel_put2(data, x, y, color);
      }
      for(int g = drawEnd; g < screenHeight; g++)
      {
        if (g >= 0)
          my_mlx_pixel_put2(data, x, g, data->txt.f_color);
      }
    }
}
