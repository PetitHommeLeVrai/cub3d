/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:05:45 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/05/18 17:16:44 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *string, int searchedChar )
{
	int				i;
	unsigned char	sch;

	i = 0;
	sch = searchedChar;
	while (string[i])
	{
		if (string[i] == sch)
			return ((char *)&string[i]);
		i++;
	}
	if (string[i] == sch)
		return ((char *)&string[i]);
	return (NULL);
}
