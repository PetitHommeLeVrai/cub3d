/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:50:57 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/22 17:03:23 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "cub3d.h"

# define WIDTH 900
# define HEIGHT 900

typedef enum e_err_msg
{
	E_ACCESS = 1,
	E_IMAP,
	E_ARG,
	E_MLX,
	E_LENGHT
}				t_err_msg;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr;
	char		*n_path;
	char		*s_path;
	char		*w_path;
	char		*e_path;
	char		*f_color;
	char		*c_color;
	char		**map;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx;

typedef struct s_txtr
{
	void		*img_north;
	void		*img_south;
	void		*img_west;
	void		*img_east;
}				t_txtr;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
}				t_player;

typedef struct s_data
{
	t_mlx		img;
	t_txtr		txtr;
	t_player	player;
}				t_data;

#endif
