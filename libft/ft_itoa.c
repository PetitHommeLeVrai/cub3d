/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:50:01 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/16 14:05:50 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	len(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	else if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		i;

	nb = n;
	i = len(nb);
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
		str[0] = 48;
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	while (nb > 0)
	{
		str[i--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *s = ft_itoa(0);
// 	// printf("%s\n", s);
// 	free(s);
// }
