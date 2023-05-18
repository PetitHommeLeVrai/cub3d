/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 22:30:59 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/05 12:22:21 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}

// #include <stdio.h>
// #include<fcntl.h>
// #include<errno.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	int	fd;

// 	fd = open("test", O_RDWR);
// 	ft_putstr_fd("Beautiful World", fd);
// }
