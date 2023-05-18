/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:50:28 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/04/23 19:05:06 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper( int character )
{
	if (character >= 'a' && character <= 'z')
		return (character - 32);
	return (character);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%c\n", ft_toupper('a'));
// }
