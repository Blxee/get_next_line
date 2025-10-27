/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:12:41 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/27 09:13:42 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buf[128][BUFFER_SIZE] = {0};
	long			size;
	unsigned long	i;
	unsigned long	j;
	char			*line;

	if (fd < 0)
		return (NULL);
	line = NULL;
	i = 0;
	while (buf[fd][i] != '\0' && buf[fd][i] != '\n')
		i++;
	if (ft_strnextend(&line, buf[fd], i) == NULL)
		return (NULL);
	while (1)
	{
		size = read(fd, buf[fd], BUFFER_SIZE);
		if (size < 0)
			break ;
		i = 0;
		while (i < size && buf[fd][i] != '\n')
			i++;
		if (ft_strnextend(&line, buf[fd], i) == NULL)
			break ;
		if (size < BUFFER_SIZE || buf[fd][i] == '\n')
			break ;
	}
	if (buf[fd][i] == '\n')
	{
		i++;
		j = 0;
		while (i < BUFFER_SIZE && buf[fd][i] != '\0')
			buf[fd][j++] = buf[fd][i++];
		buf[fd][j++] = '\0';
	}
	return (line);
}
