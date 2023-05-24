/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:43:14 by mmeguedm          #+#    #+#             */
/*   Updated: 2023/05/24 15:16:01 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			i;
	long long	res;
	int			neg;

	neg = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res * neg > 2147483647)
			return (-1);
		else if (res * neg < -2147483648)
			return (-1);
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * neg);
}
