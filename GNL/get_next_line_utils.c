/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:07:53 by bmachado          #+#    #+#             */
/*   Updated: 2021/03/04 14:09:37 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		ls1;
	int		ls2;
	char	*str;

	if (s1 && s2)
	{
		ls1 = ft_strlen(s1);
		ls2 = ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (ls1 + ls2 + 1));
		if (!str)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[ls1] = s2[i];
			ls1++;
		}
		str[ls1] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strdup(char const *s1)
{
	int		i;
	size_t	l;
	char	*s2;

	i = 0;
	l = ft_strlen(s1) + 1;
	s2 = (char *)malloc(sizeof(char) * l);
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t n)
{
	size_t	a;
	size_t	b;
	char	*str;
	size_t	real_size;

	real_size = ft_strlen(s);
	if (real_size < n)
		n = real_size;
	str = (char *)malloc(sizeof(*s) * (n + 1));
	if (!str)
		return (NULL);
	a = 0;
	b = 0;
	while (s[a])
	{
		if (a >= start && b < n)
		{
			str[b] = s[a];
			b++;
		}
		a++;
	}
	str[b] = '\0';
	return (str);
}
