/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:25:30 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/06 12:07:34 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	int c = -100;
// 	while (c < 500)
// 	{
// 	if ((ft_isalpha(c) > 0 && isalpha(c) > 0) 
//	|| (ft_isalpha(c) == 0 && isalpha(c) == 0))
// 		printf ("\033[0;32mOK\033[00m\n");
// 	else
// 	{
// 		printf("\033[1;31mKO\033[00m\n");
// 		return (0);
// 	}
// 	c++;
// 	}
// }
