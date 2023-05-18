/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:18:58 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/05/18 17:18:02 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int searchedChar )
{
	int	i;

	i = ft_strlen((char *)str);
	if (!str)
		return (NULL);
	str += ft_strlen((char *)str);
	while (i-- >= 0)
	{
		if (*str == (unsigned char)searchedChar)
			return ((char *)&(*str));
		str--;
	}
	return (NULL);
}
