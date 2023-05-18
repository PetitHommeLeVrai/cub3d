/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:57:00 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/16 14:05:41 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c > 31 && c < 127);
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	int c = -255;
// 	while (c < 255)
// 	{
// 		if ((ft_isprint(c) > 0 && isprint(c) > 0)
//			|| (ft_isprint(c) == 0 && isprint(c) == 0))
// 			printf ("\033[0;32mOK\033[00m\n");
// 		else
// 		{
// 			printf("\033[1;31mKO\033[00m\n");
// 			printf("%d\n%c\n", c, c);
// 			return (0);
// 		}
// 		c++;
// 	}
// }
