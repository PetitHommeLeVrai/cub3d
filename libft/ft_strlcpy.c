/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:53:44 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/07 19:27:58 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;

// 	i = 0;
// 	if (size != 0)
// 	{
// 		while (src[i] && i < (size - 1))
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = '\0';
// 	}
// 	return (ft_strlen(src));
// }

// void	ft_KO(int c)
// {
// 	printf("\033[1;31m%d. KO\033[00m\n", c);
// }

// void	ft_OK(int c)
// {
// 	printf("\033[1;32m%d. OK\033[00m\n", c);
// }
// #include <stdio.h>
// #include <bsd/string.h>
// #include "libft.h"

// int	main(void)
// {
// 	char	*s1 = "Beautiful World";
// 	char	s2[100];
// 	char	s3[100];

// 	printf("Generating test...\n\n");
// 	if (ft_strlcpy(s1, s2, ft_strlen(s1) != strlcpy(s1, s3, ft_strlen(s1))))
// 	{
// 		ft_KO(1);
// 		printf("Expected   :   %ld   %s\nGot   :   %ld   %s\n", 
//				strlcpy(s1, s2, ft_strlen(s1)), s2, 
//					strlcpy(s1, s3, ft_strlen(s1)), s3);
// 	}
// 	else
// 		ft_OK(1);
// }
