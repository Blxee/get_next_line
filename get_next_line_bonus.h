/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:11:20 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/05 11:24:00 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (32)
# endif

# ifndef FD_MAX
#  define FD_MAX (2048)
# endif

char			*get_next_line(int fd);

char			*ft_strchr(char **s, char c, size_t n);
void			*ft_realloc(void *mem, unsigned long old_size,
					unsigned long new_size);
unsigned long	ft_strlen(const char *str);
void			*ft_strnextend(char **s1, const char *s2, unsigned long n);
void			ft_trunc_start(char **str, size_t len, size_t size, char *endl);

#endif
