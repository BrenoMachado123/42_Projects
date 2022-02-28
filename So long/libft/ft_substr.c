/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:49:27 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/15 11:32:31 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
