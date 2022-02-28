/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilstwo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:40:54 by bmachado          #+#    #+#             */
/*   Updated: 2021/05/05 15:46:57 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

int	ft_tolower(int c)
{
	if (ft_isalpha(c) == 1)
	{
		if (c >= 65 && c <= 90)
			return (c + 32);
		else
			return (c);
	}
	return (c);
}

char	*ft_str_tolower(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	return (str);
}

int	pointer_len(unsigned long p, t_flags *flags)
{
	if (p == 0)
		flags->len = 1;
	while (p != 0)
	{
		p /= 16;
		flags->len++;
	}
	return (flags->len + 2);
}
