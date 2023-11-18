/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:45:25 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/22 14:00:10 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	if (c == 0)
		return ((char *)s);
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*gnl_ft_strjoin(char *nl_str, char *buff)
{
	int		i1;
	int		i2;
	char	*str;

	if (!nl_str)
	{
		nl_str = (char *)malloc(sizeof(char) * 1);
		nl_str[0] = '\0';
	}
	if (!nl_str || !buff)
		return (free(nl_str), NULL);
	str = malloc(sizeof(char) * ((ft_strlen(nl_str) + ft_strlen(buff)) + 1));
	if (!str)
		return (free(nl_str), NULL);
	i1 = -1;
	i2 = 0;
	if (nl_str)
		while (nl_str[++i1] != '\0')
			str[i1] = nl_str[i1];
	while (buff[i2])
		str[i1++] = buff[i2++];
	str[ft_strlen(nl_str) + ft_strlen(buff)] = '\0';
	free(nl_str);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
