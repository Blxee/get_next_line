/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:32:03 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/31 19:42:01 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	s_buf[FD_MAX][BUFFER_SIZE] = {0};
	long		size;
	long		len;
	char		*line;
	char		*endl;

	line = NULL;
	size = BUFFER_SIZE;
	while (size >= 0)
	{
		len = size;
		endl = (char *)ft_memchr(s_buf[fd], '\n', size);
		if (endl)
			len = endl - s_buf[fd] + 1;
		ft_strnextend(&line, s_buf[fd], len);
		if (endl || size < BUFFER_SIZE)
			break ;
		size = read(fd, s_buf[fd], BUFFER_SIZE);
	}
	if (len == 0)
		len = ft_strlen(s_buf[fd]);
	ft_trunc_start(s_buf[fd], len, BUFFER_SIZE);
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	return (line);
}
