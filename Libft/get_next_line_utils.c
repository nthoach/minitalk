/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:46:38 by nthoach           #+#    #+#             */
/*   Updated: 2023/11/25 16:54:45 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_len(char	*s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	gnl_strchr(char	*buffer, char chr)
{
	size_t	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == chr)
			return (1);
		i++;
	}
	return (0);
}

void	gnl_bzero(void *s, size_t n)
{
	size_t	i;
	char	*cast;

	i = 0;
	cast = (char *)s;
	while (i < n)
	{
		cast[i] = '\0';
		i++;
	}
}

void	*gnl_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (gnl_calloc(1, 1));
	ptr = malloc(count * size * sizeof(char));
	if (!ptr)
		return (NULL);
	gnl_bzero(ptr, count * size);
	return (ptr);
}
