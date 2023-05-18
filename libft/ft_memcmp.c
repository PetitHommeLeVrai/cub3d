/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:06:35 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/04 20:51:00 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size )
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = -1;
	s1 = (unsigned char *)pointer1;
	s2 = (unsigned char *)pointer2;
	while (++i < size)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

// #include <string.h>

// int main(void)
// {
// 	char	*s1 = "Beautiful World";
// 	char	*s2 = "Beautiful Korld";

// 	printf("memcmp    : %d\n", memcmp(s1, s2, 15));
// 	printf("ft_memcmp : %d\n", ft_memcmp(s1, s2, 15));
// }
