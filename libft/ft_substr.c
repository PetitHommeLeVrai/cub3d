/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 08:51:16 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/16 14:08:12 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static int	ft_checkmalloc(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while ((i < len) && start < ft_strlen(s) && s[start])
	{
		i++;
		start++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;
	size_t	smalloc;

	smalloc = ft_checkmalloc((char *)s, start, len);
	i = 0;
	p = malloc(sizeof(char) * (smalloc + 1));
	if (!p || !s)
		return (NULL);
	while (s[i] && len-- && ft_strlen((char *)s) > start)
	{
		p[i] = s[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

// #include <stdio.h>
// #ifdef MAIN

// int	main(void)
// {
// 	char *s = ft_substr("tripouille", 0, 42000);
// 	free(s);
// }

// #endif
