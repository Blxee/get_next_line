/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:12:41 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/30 12:11:19 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_trunc_start(char buf[MAX_FDS][BUFFER_SIZE], int fd, int i)
{
	unsigned long	j;

	if (buf[fd][i] == '\n')
	{
		i++;
		j = 0;
		while (i < BUFFER_SIZE && buf[fd][i] != '\0')
			buf[fd][j++] = buf[fd][i++];
		buf[fd][j++] = '\0';
	}
}

char	*get_next_line(int fd)
{
	static char		buf[MAX_FDS][BUFFER_SIZE] = {0};
	long			size;
	unsigned long	i;
	char			*line;

	if (fd < 0)
		return (NULL);
	line = NULL;
	i = 0;
	while (i < BUFFER_SIZE && buf[fd][i] != '\0' && buf[fd][i] != '\n')
		i++;
	if (buf[fd][0] != -1)
	{
		line = ft_strnextend(&line, buf[fd], i);
		if (line == NULL)
			return (NULL);
	}
	while (1)
	{
		size = read(fd, buf[fd], BUFFER_SIZE);
		if (size < 0)
			return (NULL);
		i = 0;
		while (i < size && buf[fd][i] != '\n')
			i++;
		if (ft_strnextend(&line, buf[fd], i) == NULL || buf[fd][i] == '\n')
			break ;
		if (size < BUFFER_SIZE)
		{
			i = 0;
			while (i < BUFFER_SIZE)
				buf[fd][i++] = '\0';
			buf[fd][0] = -1;
			break ;
		}
	}
	return (ft_trunc_start(buf, fd, i), line);
}
