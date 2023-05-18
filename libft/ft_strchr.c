/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:05:45 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/16 14:09:03 by mmeguedm         ###   ########.fr       */
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

// #include <string.h>
// #include <stdio.h>
// #include "libft.h"

// void	ft_KO(int c)
// {
// 	printf("\033[1;31m%d. KO\033[00m\n", c);
// }

// void	ft_OK(int c)
// {
// 	printf("\033[1;32m%d. OK\033[00m\n", c);
// }

// int	main(void)
// {
// 	char	*s = "Beautiful World";
// 	char	*find;
// 	char	*find1;

// 	find = NULL;
// 	find1 = NULL;
// 	find = ft_strchr(s, 0);
// 	find1 = strchr(s, 0);
// 	if (!find && !find1)
// 		ft_OK(1);
// 	else if (find && find1)
// 	{
// 		ft_OK(1);
// 		printf("Got        :   %s\n", find);
// 		printf("Expected   :   %s\n", find1);
// 	}

// 	if (!memcmp(find, find1, strlen(s)))
// 		ft_OK(1);
// 	elsecd
// 	{
// 		ft_KO(1);
// 		printf("Got        :   %s\n", find);
// 		printf("Expected   :   %s\n", find1);
// 	}
// }
