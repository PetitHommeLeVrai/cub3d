/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:27:02 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/06 12:08:42 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	int c = 0;
// 	while (c < 600)
// 	{
// 		if ((ft_isdigit(c) > 0 && isdigit(c) > 0) 
// 		|| (ft_isdigit(c) == 0 && isdigit(c) == 0))
// 			printf ("\033[0;32mOK\033[00m\n");
// 		else
// 		{
// 			printf("\033[1;31mKO\033[00m\n");
// 			return (0);
// 		}
// 		c++;
// 	}
// }
