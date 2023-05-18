/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:31:04 by aboyer            #+#    #+#             */
/*   Updated: 2022/11/09 12:31:06 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_strs(char const *str, char ch)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ch)
			i++;
		if (str[i] != 0)
			count++;
		while (str[i] && !(str[i] == ch))
			i++;
	}
	return (count);
}

int	ft_strlen_sep(char const *str, char ch)
{
	int	i;

	i = 0;
	while (str[i] && !(str[i] == ch))
		i++;
	return (i);
}

char	*ft_word(char const *str, char ch)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (ft_strlen_sep(str, ch) + 1));
	if (!word)
		return (NULL);
	while (i < ft_strlen_sep(str, ch))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	result = malloc(sizeof(char *) * (count_strs(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			s++;
		if (s[i] != 0)
		{
			result[j] = ft_word(s, c);
			j++;
		}
		while (s[i] && !(s[i] == c))
			s++;
	}
	result[j] = 0;
	return (result);
}