/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_int_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:34:47 by bmachado          #+#    #+#             */
/*   Updated: 2021/05/05 15:28:11 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_nbr_chr(int n, t_flags *flag)
{
	char	*takenum;
	char	*alloc;

	takenum = ft_itoa(n);
	alloc = ft_strdup(takenum);
	free(takenum);
	flag->len = ft_strlen(takenum);
	if (n < 0 && flag->dot == 1)
	{
		flag->width -= 1;
		flag->len -= 1;
		flag->neg = 1;
	}
	free(alloc);
	return (NULL);
}

int	deal_negative(int n, t_flags *flags)
{
	if (n == 0 && flags->prec == 0 && flags->dot == 1)
	{
		flags->error = 1;
		flags->len = 0;
		return (0);
	}
	if (n < 0)
	{
		flags->neg = 1;
		n *= -1;
	}
	else
		flags->neg = 0;
	return (n);
}

int	ft_dotpreczero(t_flags flag)
{
	int	count;

	count = 0;
	if (flag.prec > flag.len)
	{
		if (!(flag.prec < flag.width) || flag.minus == 0)
			count += ft_width(flag.width, flag.prec, 0);
		if (flag.neg == 1)
			ft_putchar_fd('-', 1);
	}
	else if (flag.prec <= flag.len)
	{
		if (!(flag.prec < flag.width) || flag.minus == 0)
			count += ft_width(flag.width, flag.len, 0);
		if (flag.neg == 1)
			ft_putchar_fd('-', 1);
	}
	return (count);
}
