/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_utils.c                               	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:43:01 by bmachado          #+#    #+#             */
/*   Updated: 2021/05/05 15:51:03 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*base_convert(unsigned long ul_save, int base, char *conv, int cnt)
{
	while (ul_save != 0)
	{
		if ((ul_save % base) < 10)
			conv[cnt - 1] = (ul_save % base) + 48;
		else
			conv[cnt - 1] = (ul_save % base) + 55;
		ul_save /= base;
		cnt--;
	}
	return (conv);
}

char	*ft_ul_base(unsigned long ul, int base)
{
	char			*conv_num;
	unsigned long	ul_save;
	int				count;

	ul_save = ul;
	count = 0;
	if (ul == 0)
		return (ft_strdup("0"));
	while (ul != 0)
	{
		ul /= base;
		count++;
	}
	conv_num = malloc(sizeof(char) * (count + 1));
	if (!conv_num)
		return (0);
	conv_num[count] = '\0';
	conv_num = base_convert(ul_save, base, conv_num, count);
	return (conv_num);
}

static int	ulen(unsigned long nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*uft_itoa(unsigned long nb)
{
	char	*str;
	long	n;
	int		i;

	n = nb;
	i = ulen(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		return ("0");
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}
