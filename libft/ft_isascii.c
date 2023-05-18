/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:32:16 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/06 12:19:50 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	int c = -255;
// 	while (c < 255)
// 	{
// 		if ((ft_isascii(c) > 0 && isascii(c) > 0) 
//		|| (ft_isascii(c) == 0 && isascii(c) == 0))
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
