/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_unsigned_dot.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:38:52 by bmachado          #+#    #+#             */
/*   Updated: 2021/05/05 15:29:42 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	deal_unsigned(unsigned int n, t_flags *flags)
{
	if (n == 0 && flags->prec == 0 && flags->dot == 1)
	{
		flags->error = 1;
		flags->len = 0;
		return (0);
	}
	return (n);
}

char	*convert_unbr_chr(int n, t_flags *flags)
{
	char	*takenum;
	char	*alloc;

	takenum = ft_u_itoa(n);
	alloc = ft_strdup(takenum);
	free(takenum);
	flags->len = ft_strlen(alloc);
	free(alloc);
	return (NULL);
}

int	ft_udotpreczero(t_flags flag)
{
	int	count;

	count = 0;
	if (flag.prec > flag.len)
	{
		if (!(flag.prec < flag.width) || flag.minus == 0)
			count += ft_width(flag.width, flag.prec, 0);
	}
	else if (flag.prec <= flag.len)
	{
		if (!(flag.prec < flag.width) || flag.minus == 0)
			count += ft_width(flag.width, flag.len, 0);
	}
	return (count);
}

int	ft_treat_dot_uint(unsigned int n, t_flags flag)
{
	int	count;

	count = 0;
	if (flag.prec > flag.len)
	{
		count += ft_udotpreczero(flag);
		count += ft_width(flag.prec, flag.len, 1);
		ft_uputnbr_fd(n, 1);
		if (flag.prec < flag.width && flag.minus == 1)
			count += ft_width(flag.width, flag.prec, 0);
	}
	else if (flag.prec <= flag.len)
	{
		count += ft_udotpreczero(flag);
		count += ft_width(flag.prec, flag.len, 0);
		if (flag.error != 1)
			ft_uputnbr_fd(n, 1);
		if (flag.prec < flag.width && flag.minus == 1)
			count += ft_width(flag.width, flag.len, 0);
	}
	return (count);
}
