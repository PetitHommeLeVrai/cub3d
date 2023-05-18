/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:54:24 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/05/18 17:18:14 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_charinset(char c, char const *s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*s1trim;

	i = 0;
	end = ft_strlen((char *)s1);
	start = 0;
	while (s1[start] && ft_charinset(s1[start], set))
		start++;
	while ((end > start) && (ft_charinset(s1[end - 1], set)))
		end--;
	s1trim = malloc(sizeof(char) * (end - start + 1));
	if (!s1trim)
		return (NULL);
	while (start < end)
		s1trim[i++] = s1[start++];
	s1trim[i] = '\0';
	return (s1trim);
}
