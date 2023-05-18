/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 22:38:26 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/05 12:21:56 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
	ft_putchar_fd('\n', fd);
}

// #include <stdio.h>
// #include<fcntl.h>
// #include<errno.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	int	fd;

// 	fd = open("test", O_RDWR);
// 	ft_putendl_fd("Beautiful World", fd);
// }
