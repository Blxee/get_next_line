/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:32:03 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/05 11:02:02 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*s_buf = NULL;
	long		size;
	long		len;
	char		*line;
	char		*endl;

	line = NULL;
	size = (long)BUFFER_SIZE;
	while (size >= 0)
	{
		len = size;
		endl = (char *)ft_strchr(&s_buf, '\n', size);
		if (endl)
			len = endl - s_buf + 1;
		ft_strnextend(&line, s_buf, len);
		ft_trunc_start(&s_buf, len, (size_t)BUFFER_SIZE, endl);
		if (!s_buf || endl || (size_t)size < (size_t)BUFFER_SIZE)
			break ;
		size = read(fd, s_buf, (size_t)BUFFER_SIZE);
	}
	if (line && ft_strlen(line) == 0)
		return (free(line), NULL);
	return (line);
}
