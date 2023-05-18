/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:24:57 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/16 15:11:33 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((char *)pointer)[i] = value;
		i++;
	}
	return (pointer);
}
	/*Transtypage de pointeur générique vers un pointeur de char*/

// int	main(void)
// {
// 	int array [] = { 54, 85, 20, 63, 21 };
// 	int array2 [] = { 54, 85, 20, 63, 21 };
//     size_t size = sizeof( int ) * 5;
//     int i;

// 	i = 0;
//     /* Display the initial values */
// 	printf("//////TABLE DISPLAY//////\n");
//     for( i=0; i<5; i++) {
//         printf("tab[%d] : %d\n", i, array[ i ] );
//     }
//     printf( "\nGenerating test...\n");

// 	memset(array , 0, size);
// 	ft_memset(array2, 0, size);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("TEST %d\n", i);
// 		if (array[i] != array2[i])
// 		{
// 			printf("\033[1;31mKO\033[00m\n");
// 		 	printf("%-*s->  array[%d]   :  %d\n%-*s->  array2[%d]  :  %d\n", 15,
//			"Expected", i, array[i], 15, "Got", i, array2[i]);
// 			return (0);
// 		}
// 		else
// 			printf("\033[1;32mOK\033[00m\n");
// 		i++;
// 	}
// 	printf("TEST 5\n");

// 	char s[] = "Beautiful World";
// 	char s1[] = "Beautiful World";
// 	size = sizeof(char) * ft_strlen(s);
// 	memset(s, 'a', size);
// 	ft_memset(s1, 'a', size);
// 	if (!ft_strncmp(s, s1, size))
// 	{
// 		printf("\033[1;31mKO\033[00m\n");
// 		printf("s   :   %s\n", s);
// 		printf("s1  :   %s\n", s1);
// 	}
// 	else
// 		printf("\033[1;32mOK\033[00m\n");
// 	printf("TEST 6\n");

// 	memset(s, 'a', size);
// 	ft_memset(s1, 'a', size);
// 	if (ft_strncmp(s, s1, size))
// 	{
// 		printf("\033[1;31mKO\033[00m\n");
// 		printf("%s : s\n", s);
// 		printf("%s : s1\n", s1);
// 	}
// 	else
// 		printf("\033[1;32mOK\033[00m\n");

// 	printf("TEST 7\n");

// 	if (ft_strncmp(s, s1, size))
// 	{
// 		printf("\033[1;31mKO\033[00m\n");
// 		printf("%s : s\n", s);
// 		printf("%s : s1\n", s1);
// 	}
// 	else
// 		printf("\033[1;32mOK\033[00m\n");

// 	printf("Test completed...no errors reported\n");
// }
