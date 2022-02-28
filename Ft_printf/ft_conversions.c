/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:16:11 by bmachado          #+#    #+#             */
/*   Updated: 2021/05/05 15:24:55 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(int c, t_flags flag)
{
	int	count;

	count = 0;
	if (flag.minus == 1)
		ft_putchar_fd(c, 1);
	count += ft_width(flag.width, 1, 0);
	if (flag.minus == 0)
		ft_putchar_fd(c, 1);
	return (count + 1);
}

int	ft_str(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (!str)
	{
		str = "(null)";
		if (flags.star == 1)
			flags.error = 1;
	}
	if (flags.minus == 1 && flags.dot == 0)
	{
		ft_putstr_fd(str, 1);
		count += ft_width(flags.width, ft_strlen(str), 0);
	}
	if (flags.dot == 1)
		count += ft_dot_str(str, &flags);
	if (flags.minus == 0 && flags.dot == 0)
	{
		count += ft_width(flags.width, ft_strlen(str), 0);
		ft_putstr_fd(str, 1);
	}
	if (flags.dot == 0)
		count += ft_strlen(str);
	return (count);
}

int	ft_pointer(unsigned long p, t_flags flag)
{
	int		count;
	char	*pointer;

	count = 0;
	count += pointer_len(p, &flag);
	if (flag.minus == 0)
		count += ft_width(flag.width, flag.len + 2, 0);
	pointer = ft_ul_base(p, 16);
	pointer = ft_str_tolower(pointer);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(pointer, 1);
	if (flag.minus == 1 && flag.width >= flag.len + 2)
		count += ft_width(flag.width, flag.len + 2, 0);
	free(pointer);
	return (count);
}

int	ft_int(int n, t_flags flag)
{
	int		count;
	char	*tmp;

	count = 0;
	tmp = convert_nbr_chr(n, &flag);
	if (flag.neg == 1)
		count += 1;
	if (flag.minus == 1 && flag.dot == 0)
	{
		ft_putnbr_fd(n, 1, flag);
		count += ft_width(flag.width, flag.len, 0);
	}
	n = deal_negative(n, &flag);
	if (flag.dot == 1)
		count += ft_treat_dot_int(n, flag);
	if (flag.minus == 0 && flag.dot == 0)
	{
		if (flag.neg == 1 && flag.zero == 1)
			ft_putchar_fd('-', 1);
		count += ft_width(flag.width, flag.len, flag.zero);
		if (flag.neg == 1 && flag.zero == 0)
			ft_putchar_fd('-', 1);
		ft_putnbr_fd(n, 1, flag);
	}
	return (count + flag.len);
}

int	ft_unint_hexa(int input, unsigned int n, t_flags flags)
{
	int	count;

	count = 0;
	if (input == 'u')
		count += ft_unsigned(n, flags);
	else if (input == 'x' || input == 'X')
		count += ft_hexa(input, n, flags);
	return (count);
}
