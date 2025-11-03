/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:32:03 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/03 16:09:45 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	s_buf[BUFFER_SIZE] = {0};
	long		size;
	long		len;
	char		*line;
	char		*endl;

	line = NULL;
	size = BUFFER_SIZE;
	while (size >= 0)
	{
		len = size;
		endl = (char *)ft_memchr(s_buf, '\n', size);
		if (endl)
			len = endl - s_buf + 1;
		ft_strnextend(&line, s_buf, len);
		ft_trunc_start(s_buf, len, BUFFER_SIZE);
		if (endl || size < BUFFER_SIZE)
			break ;
		size = read(fd, s_buf, BUFFER_SIZE);
	}
	if (line && ft_strlen(line) == 0)
		return (free(line), NULL);
	return (line);
}
