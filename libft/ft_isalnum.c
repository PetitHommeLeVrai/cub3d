/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:24:50 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/16 14:02:23 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {	
// 	int c = 0;
// 	while (c < 500)
// 	{
// 		if ((ft_isalnum(c) > 0 && isalnum(c) > 0)
// 		|| (ft_isalnum(c) == 0 && isalnum(c) == 0))
// 			// printf ("\033[0;32mOK\033[00m\n");
// 			printf("\n");
// 		else
// 		{
// 			printf("\033[1;31mKO\033[00m\n");
// 			printf("%d\n%c\n", c, c);
// 			// return (0);
// 		}
// 		c++;
// 	}
// }
