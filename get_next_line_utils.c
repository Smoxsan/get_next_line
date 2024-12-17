/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:03:34 by fkonig            #+#    #+#             */
/*   Updated: 2024/12/16 17:17:28 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int search_str)
{
	unsigned char	r;

	r = (unsigned char)search_str;
	while (*str)
	{
		if (*str == r)
			return ((char *)str);
		str++;
	}
	if (r == '\0')
		return ((char *)str);
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(str) + 1;
	ptr = (char *)malloc(len);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str, len);
	return (ptr);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*result;

	l1 = 0;
	l2 = 0;
	if (!s1 && !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	result = malloc(l1 + l2 + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, l1 + 1);
	ft_strlcpy(result + l1, s2, l2 + 1);
	return (result);
}
