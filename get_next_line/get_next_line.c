/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyer <aboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:45:06 by aboyer            #+#    #+#             */
/*   Updated: 2023/05/22 14:00:52 by aboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_nl_str(int fd, char *nl_str)
{
	char	*buff;
	int		i;

	i = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(nl_str, '\n') && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		nl_str = gnl_ft_strjoin(nl_str, buff);
	}
	free(buff);
	return (nl_str);
}

char	*get_line(char *nl_str)
{
	char	*line;
	int		i;

	i = 0;
	if (!nl_str[i])
		return (NULL);
	while (nl_str[i] && nl_str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (nl_str[i] && nl_str[i] != '\n')
	{
		line[i] = nl_str[i];
		i++;
	}
	if (nl_str[i] == '\n')
	{
		line[i] = nl_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*new_next_line(char *nl_str)
{
	char	*nnl_str;
	int		i;
	int		j;

	i = 0;
	while (nl_str[i] && nl_str[i] != '\n')
		i++;
	if (!nl_str[i])
	{
		free(nl_str);
		return (NULL);
	}
	nnl_str = (char *)malloc(sizeof(char) * ((ft_strlen(nl_str) - i) + 1));
	if (!nnl_str)
		return (NULL);
	i++;
	j = 0;
	while (nl_str[i])
		nnl_str[j++] = nl_str[i++];
	nnl_str[j] = '\0';
	free(nl_str);
	return (nnl_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*nl_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nl_str = get_nl_str(fd, nl_str);
	if (!nl_str)
		return (NULL);
	line = get_line(nl_str);
	nl_str = new_next_line(nl_str);
	return (line);
}
