/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:32:03 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/05 11:25:57 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*s_buf[FD_MAX] = {NULL};
	long		size;
	long		len;
	char		*line;
	char		*endl;

	line = NULL;
	size = (long)BUFFER_SIZE;
	while (size >= 0)
	{
		len = size;
		endl = (char *)ft_strchr(&s_buf[fd % FD_MAX], '\n', size);
		if (endl)
			len = endl - s_buf[fd % FD_MAX] + 1;
		ft_strnextend(&line, s_buf[fd % FD_MAX], len);
		ft_trunc_start(&s_buf[fd % FD_MAX], len, (size_t)BUFFER_SIZE, endl);
		if (!s_buf[fd % FD_MAX] || endl || (size_t)size < (size_t)BUFFER_SIZE)
			break ;
		size = read(fd, s_buf[fd % FD_MAX], (size_t)BUFFER_SIZE);
	}
	if (line && ft_strlen(line) == 0)
		return (free(line), NULL);
	return (line);
}
