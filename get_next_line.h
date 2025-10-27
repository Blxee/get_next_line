/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:11:20 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/27 08:59:38 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (32)
# endif

char			*get_next_line(int fd);
void			*ft_realloc(void *mem, unsigned long size);
unsigned long	ft_strlen(const char *str);
void			*ft_strnextend(char **s1, const char *s2, unsigned long n);

#endif
