/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:12:41 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/15 15:15:29 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE];
	long			size;
	unsigned long	i;
	char			*line;

	line = NULL;
	while (1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
		i = 0;
		while (i < size && buf[i] != '\n')
			i++;
		ft_strnextend(&line, buf, i);
	}
	return (line);
}
