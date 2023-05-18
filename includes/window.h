/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:49:56 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/18 16:51:37 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

int	init(t_data *data, int ac, char **av);
int	destroy_win(t_data *data);
int	draw(t_data *data);
int	handle_keyrelease(int keysym, t_data *data);
int	handle_input(int keysym, t_data *data);

#endif
