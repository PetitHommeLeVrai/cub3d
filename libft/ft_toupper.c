/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:50:28 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/05/18 17:18:33 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper( int character )
{
	if (character >= 'a' && character <= 'z')
		return (character - 32);
	return (character);
}
