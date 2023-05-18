/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:48:10 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/04 22:44:06 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <stdio.h>
// #include<fcntl.h>
// #include<errno.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	int	fd = open("test", O_RDONLY);
// 	int	len;
// 	char *c = malloc(sizeof(char) + 10);
// 	printf("fd =  %d\n", fd);
// 	//ft_putchar_fd('a', fd);
// 	len = read(fd, c, 10);
// 	printf("len : %d\n", len);
// 	c[len] = '\0';
// 	printf("c : %s\n", c);
// 	// ft_putchar_fd('a', fichier);

// #include<stdio.h>
// #include <fcntl.h>
// int main()
// {
// int fd, sz;
// char *c = (char *) calloc(100, sizeof(char));

// fd = open("test", O_RDONLY);
// if (fd < 0) { perror("r1"); exit(1); }

// sz = read(fd, c, 10);
// printf("called read(% d, c, 10). returned that"
//         " %d bytes were read.\n", fd, sz);
// c[sz] = '\0';
// printf("Those bytes are as follows: %s\n", c);
// }
