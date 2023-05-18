/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:49:56 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/18 17:52:02 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "tools.h"

int	init(t_data *data, int ac, char **av);
int	destroy_win(t_data *data);
int	draw(t_data *data);
int	handle_keyrelease(int keysym, t_data *data);
int	handle_input(int keysym, t_data *data);

#endif
