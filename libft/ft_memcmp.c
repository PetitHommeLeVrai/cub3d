/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:06:35 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/05/18 17:14:44 by mmeguedm         ###   ########.fr       */
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
