/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:43:14 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/06/03 18:56:23 by mmeguedm         ###   ########.fr       */
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
			return (0);
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * neg);
}

// #ifdef MAIN
// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>

// void	ft_print_OK(int error, int c)
// {
// 	if (error)
// 		printf("\033[1;31m%d. KO\033[00m\n", c);
// 	else
// 		printf("\033[1;32m%d. OK\033[00m\n", c);
// }

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 	{
// 		printf("Nombre d'arguments invalide");
// 		return (0);
// 	}

// 	int ft = ft_atoi(argv[1]);
// 	int og = atoi(argv[1]);
// 	int res = (ft != og);
// 	printf("%d\n%d\n", ft, og);
// 	ft_print_OK(res, 1);
// }

// #endif
