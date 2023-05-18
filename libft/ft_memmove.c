/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:44:37 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/16 14:06:16 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (((char *) src) < ((char *) dest))
	{
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	}
	else
	{
		while (n--)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

// #include <string.h>
// int main(void)
// {
// 	char	s[] = "abcdef";
// 	char	s1[] = "abcdef";

// 	ft_memmove(s + 1, s, 4);
// 	ft_memcpy(s1 + 1, s1, 4);
// 	printf("%s\n", s);
// 	printf("%s\n", s1);

// 	// memmove(s1 + 1, s1, 4);
// 	// ft_memcmp(s1 + 1, s1, 4);
// 	// printf("%s\n", s1);

// 	// void	*dest = 15;
// 	// printf("dest : %p\n", dest);
// }
