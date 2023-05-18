/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:31:43 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/04/23 19:50:01 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// #ifdef MAIN
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <time.h>

// int	ft_print_OK(int error, int c)
// {
// 	if (error)
// 		printf("\033[1;31m%d. KO\033[00m\n", c);
// 	else
// 		printf("\033[1;32m%d. OK\033[00m\n", c);
// 	return(error);
// }

// int	test(char *s1, char *s2, unsigned int n)
// {
// 	int	ft = ft_strncmp(s1, s2, n);
// 	int og = strncmp(s1, s2, n);
// 	int res = (ft != og);

// 	if (res)
// 		printf("s1: %s\ns2: %s\nft_strncmp -> 
//				%d\nstrncmp -> %d\n", s1, s2, ft, og);
// 	return (res);
// }
// #define ASCII_RANGE 126

// char	*generate(int size_max)
// {
// 	srand( time( NULL ) );
// 	int		size = rand() % size_max;
// 	char	*str = calloc(size + 1 , sizeof(char));
// 	if (!str)
// 		return (NULL);
// 	for (int i = 0; i < size; i++)
// 		str[i] = rand() % ASCII_RANGE;
// 	return (str);
// }

// int main(void)
// {
// 	// int size_max = 2;
// 	// int nb_iter = 2147483647;	
// 	char	*s1, *s2;

// 	// for (int i = 1; i < nb_iter; i++)
// 	// {
// 		s1 = "t";
// 		s2 = "";
// 		if (ft_print_OK(test(s1, s2, 0), 0))
// 			return (0);
// 	// 	free(s1);
// 	// 	free(s2);
// 	// }
// }

// #endif