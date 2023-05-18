/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:18:28 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/07 17:52:19 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (size--)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

// #include <stdlib.h>
// #include <string.h>
// #include <strings.h>

// void	ft_KO(void)
// {
// 	printf("\033[1;31mKO\033[00m\n");
// }

// void	ft_OK(void)
// {
// 	printf("\033[1;32mOK\033[00m\n");
// }

// int main(void)
// {
//     int array [] = { 54, 85, 20, 63, 21 };
//     int array2 [] = { 54, 85, 20, 63, 21 };
//     // char	*array = NULL;
//     // char	*array2 = NULL;
// 	int *copy = NULL;
//     int *copy2 = NULL;
// 	int	i = 0;

//     /* Memory allocation and copy */
//     // copy = malloc(sizeof( int ) * 5);
//     // copy2 = malloc(sizeof( int ) * 5);
//     memcpy(copy, array, 1000);
//     ft_memcpy(copy2, array2, 1000);

// 	while (i < 5)
// 	{
// 		if (copy[i] != copy2[i])
// 		{
// 			ft_KO();
// 			printf("copy[%d]  : %d\ncopy2[%d] : %d\n", i, copy[i], i, copy2[i]);
// 		}
// 		else
// 			ft_OK();
// 		i++;
// 	}
// 	i = 0;
// 	bzero(copy, 17); // VERIFY WITH YOUR OWN FUNCTION.
// 	ft_bzero(copy2, 17); // VERIFY WITH YOUR OWN FUNCTION.
// 	printf("CHECK BZERO : \n");
// 	while (i < 5)
// 	{
// 		if (copy[i] != copy2[i])
// 		{
// 			ft_KO();
// 			printf("copy[%d] : %d\ncopy2[%d] : %d\n", i, copy[i], i, copy2[i]);
// 		}
// 		else
// 			ft_OK();
// 		i++;
// 	}

// }
