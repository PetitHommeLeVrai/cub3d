/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:52:05 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/16 14:03:16 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	n;

	n = (nmemb * size);
	if (nmemb && (n / nmemb != size))
		return (NULL);
	p = (void *)malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, (size * nmemb));
	return (p);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	int	*t = calloc(1, sizeof(int));
// 	int	i;

// 	i = 1;
// 	while (i--)
// 		printf("%d ", t[i]);
// 	printf("\n");
// }
