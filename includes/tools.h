/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:50:57 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/18 14:52:13 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_north;
	void	*img_south;
	void	*img_west;
	void	*img_east;
}			t_data;

#endif
