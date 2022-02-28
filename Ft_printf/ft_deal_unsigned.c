/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:38:42 by bmachado          #+#    #+#             */
/*   Updated: 2021/05/05 15:45:49 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	putlong(long int n, int fd)
{
	if (n > 9)
		putlong(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void	ft_uputnbr_fd(unsigned int n, int fd)
{
	unsigned int	v;

	v = n;
	putlong(v, fd);
}

int	ft_unsigned(unsigned int n, t_flags flag)
{
	int		count;
	char	*tmp;

	count = 0;
	tmp = convert_unbr_chr(n, &flag);
	if (flag.minus == 1 && flag.dot == 0)
	{
		ft_uputnbr_fd(n, 1);
		count += ft_width(flag.width, flag.len, 0);
	}
	n = deal_unsigned(n, &flag);
	if (flag.dot == 1)
		count += ft_treat_dot_uint(n, flag);
	if (flag.minus == 0 && flag.dot == 0)
	{
		count += ft_width(flag.width, flag.len, flag.zero);
		ft_uputnbr_fd(n, 1);
	}
	return (count + flag.len);
}
