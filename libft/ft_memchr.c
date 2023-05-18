/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:25:06 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/04 15:23:42 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size )
{
	size_t	i;

	i = 0;
	while (size--)
	{
		if (((char *)memoryBlock)[i] == (char)searchedChar)
			return (&(((char *)memoryBlock)[i]));
		i++;
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>

// int main(void)
// {
// 	char	str[] = "Beautiful World\200";

// 	printf("%p\n", memchr(str, '\0', 14));
// 	printf("%p\n", ft_memchr(str, '\0', 14));
// }
