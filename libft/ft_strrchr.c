/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:18:58 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/05 12:19:26 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int searchedChar )
{
	int	i;

	i = ft_strlen((char *)str);
	if (!str)
		return (NULL);
	str += ft_strlen((char *)str);
	while (i-- >= 0)
	{
		if (*str == (unsigned char)searchedChar)
			return ((char *)&(*str));
		str--;
	}
	return (NULL);
}

// #ifdef MAIN

// #include <string.h>

// static void	ft_KO(int c)
// {
// 	printf("\033[1;31m%d. KO\033[00m\n", c);
// }

// static void	ft_OK(int c)
// {
// 	printf("\033[1;32m%d. OK\033[00m\n", c);
// }

// int	main(void)
// {
// 	char	*s = "bEWIUSAD";
// 	int		c = 256;
// 	s = ft_strrchr(s, c);
//	if (!strcmp(ft_strrchr(s, c), strrchr(s, c)))
// 	// {
// 		// ft_KO(1);
// 		printf("ft_strr : %s\n", ft_strrchr(s, c));
// 		printf("strr : %s\n", strrchr(s, c));
// 	// }	
// 	// else
// 		// ft_OK(1);
// }

// #endif
