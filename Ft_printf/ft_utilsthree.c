/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsthree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:22:55 by bmachado          #+#    #+#             */
/*   Updated: 2021/05/05 15:48:13 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	else
		return (0);
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

int	ft_width(int width, int minus, int has_zero)
{
	int	count;

	count = 0;
	while (width - minus > 0)
	{
		if (has_zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		width -= 1;
		count++;
	}
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t n)
{
	size_t	a;
	size_t	b;
	char	*str;
	size_t	real_size;

	str = (char *)malloc(sizeof(*s) * (n + 1));
	if (!str || s == NULL)
		return (NULL);
	real_size = ft_strlen(s);
	if (real_size < n)
		n = real_size;
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
