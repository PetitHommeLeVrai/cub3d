/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:50:57 by aboyer            #+#    #+#             */
/*   Updated: 2023/07/20 15:09:11 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "cub3d.h"

/*	Macroconstant required by the window management  */
# define WIDTH 640
# define HEIGHT 480
# define SCREENWIDTH 640
# define SCREENHEIGHT 480
# define TEXWIDTH 64
# define TEXHEIGHT 64

/*	Ascii codes  */
# define NEWLINE '\n'
# define SPACE 32

/*	Hexadecimal color code for use  */
# define BLACK		0x000000
/*----------RED----------*/
# define RED		0xFF0000
# define RED1		0xd90000
# define RED2		0x8a0000
/*--------YELLOW---------*/
# define YELLOW		0xFFDE14
# define YELLOW1	0xf29d00
# define YELLOW2	0xb87700

# define BLUE	0x0000FF
# define WHITE	0xFFFFFF
# define GREEN	0x00FF00
# define ORANGE 0xE57314

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
# define DR	0.0174533

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
	char		**map_tmp;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*win2_ptr;
	void		*img_ptr;
	void		*img2_ptr;
	char		*addr;
	char		*addr2;
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
	int			bpp;
	int			size_line;
	int			line_length;
	int			endian;
}				t_mlx;

typedef struct s_txt
{
	void		*img_north;
	void		*img_south;
	void		*img_west;
	void		*img_east;
	int			fd_north;
	int			fd_south;
	int			fd_west;
	int			fd_est;
	int			c_color;
	int			f_color;
	int			count;
	int			index_file;
}				t_txt;

typedef struct s_player
{
	double		dir_x;
	double		plane_x;
	double		plane_y;
	float		pos_x;
	float		pos_y;
	char		compass_point;
	int			case_width;
	int			case_height;
	int			p_x;
	int			p_y;
}				t_player;

typedef struct s_map
{
	int				color;
	unsigned char	wall;
	int				case_width;
	int				case_height;
	int				mx;
	int				my;
	int				mp;
	char			compass_point;
}					t_map;

typedef struct s_ray
{
	double		tex_pos;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	int			line_height;
	int			pitch;
	double		wall_x;
	int			stepx;
	int			stepy;
	double		pw_dist;
	double		ddist_x;
	double		ddist_y;
	double		raydir_x;
	double		raydir_y;
	double		camara_x;
	double		sd_x;
	double		sd_y;
	int			map_x;
	int			map_y;
	double		dir_x;
	double		diry;
	double		plane_x;
	double		plane_y;
}				t_ray;

typedef struct s_data
{
	t_mlx		img;
	t_txt		txt;
	t_player	player;
	t_ray		ray;
	t_map		map;
}				t_data;

typedef void(*t_fp_movement)(t_data *data);

/*	Required to handle key_hook  */
typedef struct s_movement
{
	unsigned int	key;
	t_fp_movement	key_fp;
}					t_movement;

#endif
