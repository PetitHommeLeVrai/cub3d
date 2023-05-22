/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:41:43 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/05/18 17:17:18 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *str, size_t lenmax)
{
	size_t	i;

	i = 0;
	while (str[i] && i < lenmax)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lendest;

	lendest = ft_strnlen(dest, size);
	j = 0;
	i = 0;
	if (size == 0 || lendest >= size)
		return (size + ft_strlen(src));
	while (dest[i])
		i++;
	while (src[j] && i + j < size - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (ft_strlen(src) + lendest);
}
