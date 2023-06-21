/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:50:57 by aboyer            #+#    #+#             */
/*   Updated: 2023/06/21 16:37:38 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "cub3d.h"

/*	Macroconstant required by the window management  */
# define WIDTH 800
# define HEIGHT 800

/*	Ascii codes  */
# define NEWLINE '\n'
# define SPACE 32

/*	Hexadecimal color code for use  */
# define BLACK	0x000000
# define RED	0xFF0000
# define BLUE	0x0000FF
# define WHITE	0xFFFFFF
# define GREEN	0x00FF00
# define ORANGE 0xE57314
# define YELLOW 0xFFDE14

/* Key code for mlx_instance  */
# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100

# define PI 3.14159265359

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
	int			*i_map;
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
	float		pos_x;
	float		pos_y;
	float		p_a;
	float		pdx;
	float		pdy;
	float		disH;
	float		disV;
	char		compass_point;
	int			case_width;
	int			case_height;
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			p_x;	// Has to be delete
	int			p_y;	// Has to be delete
}				t_player;

typedef struct s_data
{
	t_mlx		img;
	t_txt		txt;
	t_player	player;
}				t_data;

typedef void(*t_fp_movement)(t_data *data);

/*	Required to handle key_hook  */
typedef struct s_movement
{
	unsigned int	key;
	t_fp_movement	key_fp;
}					t_movement;

#endif
