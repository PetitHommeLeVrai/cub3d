/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:50:57 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/22 14:50:05 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "cub3d.h"

typedef enum e_err_msg
{
	E_ACCESS,
	E_IMAP,
	E_LENGHT
}			t_err_msg;

typedef struct s_data
{
	char	*n_path;
	char	*s_path;
	char	*w_path;
	char	*e_path;
	char	*f_color;
	char	*c_color;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_north;
	void	*img_south;
	void	*img_west;
	void	*img_east;
}			t_data;

#endif
