/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:50:57 by aboyer            #+#    #+#             */
/*   Updated: 2023/06/14 11:27:38 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "cub3d.h"

/*	Macroconstant required by the window management  */
# define WIDTH 600
# define HEIGHT 600

# define NEWLINE '\n'
# define SPACE 32

# define BLACK	0x000000
# define RED	0xFF0000
# define BLUE	0x0000FF
# define WHITE	0xFFFFFF
# define GREEN	0x00FF00

typedef enum e_err_msg
{
	E_ACCESS,
	E_IMAP,
	E_ARG,
	E_MLX,
	E_TEXTURES,
	E_ELEMENT,
	E_COLORS,
	E_CVAL,
	E_NOMEM,
	E_MAP,
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
	int			f_rgb[3];
	int			c_rgb[3];
	char		**file;
	char		**map;
	char		**map_cp;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx;

typedef struct s_txt
{
	void		*img_north;
	void		*img_south;
	void		*img_west;
	void		*img_east;
	int			count;
	int			index_file;
}				t_txt;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	int			case_width;
	int			case_height;
	int			p_x;
	int			p_y;
}				t_player;

typedef struct s_data
{
	t_mlx		img;
	t_txt		txt;
	t_player	player;
}				t_data;

#endif
