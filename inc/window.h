/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:49:56 by aboyer            #+#    #+#             */
/*   Updated: 2023/07/18 19:09:32 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "tools.h"

void	init(t_data *data, int ac, char **av);
int		draw(t_data *data);
int		handle_keyrelease(int keysym, t_data *data);
int		handle_input(int keysym, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);

#endif
