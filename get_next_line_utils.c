/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:27:28 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/15 15:30:01 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_realloc(void *mem, unsigned long size)
{
	unsigned char	*new;
	unsigned int	i;

	new = malloc(size);
	if (new == NULL)
		return (NULL);
	if (mem != NULL)
	{
		i = 0;
		while (i < size)
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

void	ft_strnextend(char **s1, const char *s2, unsigned long n)
{
	unsigned long	s1_len;
	unsigned long	s2_len;
	unsigned long	total_len;
	unsigned long	i;

	if (s1 == NULL || s2 == NULL)
		return ;
	if (*s1 == NULL)
		s1_len = 0;
	else
		s1_len = ft_strlen(*s1);
	s2_len = ft_strlen(s2);
	if (n < s2_len)
		s2_len = n;
	total_len = s1_len + s2_len + 1;
	*s1 = ft_realloc(*s1, total_len);
	i = 0;
	while (i < s2_len)
	{
		(*s1)[s1_len + i] = s2[i];
		i++;
	}
	(*s1)[s1_len + i] = '\0';
}
