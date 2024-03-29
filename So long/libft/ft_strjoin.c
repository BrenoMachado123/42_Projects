/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:50:14 by bmachado          #+#    #+#             */
/*   Updated: 2021/02/23 14:04:24 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
