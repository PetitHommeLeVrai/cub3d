/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:28:16 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/07 18:59:46 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*s2 || !s2)
		return ((char *)s1);
	if (n == 0)
		return (NULL);
	while (s1[i] && (i < n))
	{
		j = 0;
		while ((s1[i + j] == s2[j] && (i + j) < n))
		{
			if (s2[j + 1] == '\0')
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

// #include <string.h>
// #include <bsd/string.h>

// int	main(void)
// {
// 	char *s1 = "co";
// 	char *s2 = "co";
// 	// int	lenght = ft_strlen(s1);

// 	printf("strnstr     : %s\n", strnstr(s1, s2, 2));
// 	printf("ft_strnstr  : %s\n", ft_strnstr(s1, s2, 2));
// }
