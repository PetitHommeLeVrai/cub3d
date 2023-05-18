/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:25:06 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/05/18 17:14:36 by mmeguedm         ###   ########.fr       */
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
