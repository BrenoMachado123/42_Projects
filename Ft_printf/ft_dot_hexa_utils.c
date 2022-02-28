/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_hexa_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:05:23 by bmachado          #+#    #+#             */
/*   Updated: 2021/05/05 15:27:13 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_hexalen(unsigned int n, t_flags *flags)
{
	if (n == 0 && flags->prec == 0 && flags->dot == 1)
	{
		flags->error = 1;
		return (0);
	}
	if (n == 0)
		flags->len += 1;
	while (n != 0)
	{
		n /= 16;
		flags->len++;
	}
	return (flags->len);
}

static	int	ft_dot_hexa(char *hexa, t_flags flag)
{
	int	count;

	count = 0;
	if (flag.prec > flag.len)
	{
		count += ft_dotpreczero(flag);
		count += ft_width(flag.prec, flag.len, 1);
		ft_putstr_fd(hexa, 1);
		if (flag.prec < flag.width && flag.minus == 1)
			count += ft_width(flag.width, flag.prec, 0);
	}
	else if (flag.prec <= flag.len)
	{
		count += ft_dotpreczero(flag);
		count += ft_width(flag.prec, flag.len, 0);
		if (flag.error != 1)
			ft_putstr_fd(hexa, 1);
		if (flag.prec < flag.width && flag.minus == 1)
			count += ft_width(flag.width, flag.len, 0);
	}
	return (count);
}

int	ft_hexa(int input, unsigned int n, t_flags flag)
{
	int		count;
	char	*hexa;

	count = 0;
	count += ft_hexalen(n, &flag);
	hexa = ft_ul_base(n, 16);
	if (input != 'X')
		hexa = ft_str_tolower(hexa);
	if (flag.minus == 0 && flag.dot == 0)
	{
		count += ft_width(flag.width, flag.len, flag.zero);
		ft_putstr_fd(hexa, 1);
	}
	if (flag.dot == 1)
		count += ft_dot_hexa(hexa, flag);
	if (flag.minus == 1 && flag.dot == 0)
	{
		ft_putstr_fd(hexa, 1);
		count += ft_width(flag.width, flag.len, 0);
	}
	free(hexa);
	return (count);
}
