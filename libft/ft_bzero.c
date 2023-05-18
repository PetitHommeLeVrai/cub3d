/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:22:14 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/16 14:10:25 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

// #include <strings.h>
// #include <stdio.h>
// #include "libft.h"

// void	ft_KO(void)
// {
// 	printf("\033[1;31mKO\033[00m\n");
// }

// void	ft_OK(void)
// {
// 	printf("\033[1;32mOK\033[00m\n");
// }

// int	main(void)
// {
// 	char	s1[] = "aBeautiful World\n\t\t\t\200aaa";
// 	char	s2[] = "aBeautiful World\n\t\t\t\200aaa";
// 	size_t size;

// 	size = ft_strlen(s2);
// 	bzero(s2, size);
// 	ft_bzero(s1, size);
// 		if (ft_strncmp(s1, s2, size))
// 			ft_KO();
// 		else
// 			ft_OK();

// }
