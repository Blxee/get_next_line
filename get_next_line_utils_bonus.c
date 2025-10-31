/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:27:28 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/31 09:28:46 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mem;
	size_t			i;

	if (s == NULL)
		return (NULL);
	mem = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (mem[i] == (unsigned char)c)
			return ((void *)mem + i);
		i++;
	}
	return (NULL);
}

void	*ft_realloc(void *mem, unsigned long old_size, unsigned long new_size)
{
	unsigned char	*new;
	unsigned int	i;

	new = malloc(new_size);
	if (new == NULL)
	{
		if (mem != NULL)
			free(mem);
		return (NULL);
	}
	if (mem != NULL)
	{
		i = 0;
		while (i < old_size)
		{
			new[i] = ((unsigned char *)mem)[i];
			i++;
		}
		free(mem);
	}
	return (new);
}

unsigned long	ft_strlen(const char *str)
{
	unsigned long	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	*ft_strnextend(char **s1, const char *s2, unsigned long n)
{
	unsigned long	s1_len;
	unsigned long	s2_len;
	unsigned long	total_len;
	unsigned long	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = 0;
	if (*s1 != NULL)
		s1_len = ft_strlen(*s1);
	s2_len = ft_strlen(s2);
	if (n < s2_len)
		s2_len = n;
	total_len = s1_len + s2_len + 1;
	*s1 = ft_realloc(*s1, s1_len, total_len);
	if (*s1 == NULL)
		return (NULL);
	i = 0;
	while (i < s2_len)
	{
		(*s1)[s1_len + i] = s2[i];
		i++;
	}
	(*s1)[s1_len + i] = '\0';
	return (*s1);
}

void	ft_trunc_start(char *str, size_t len, size_t size)
{
	size_t	i;

	i = 0;
	while (len + i < size)
	{
		str[i] = str[len + i];
		i++;
	}
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
}
