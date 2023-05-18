/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:02:46 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/04/23 19:04:19 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower( int character )
{
	if (character >= 'A' && character <= 'Z')
		return (character + 32);
	return (character);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%c\n", ft_tolower('A'));
// }
