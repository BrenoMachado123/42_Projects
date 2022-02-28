/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:43:03 by bmachado          #+#    #+#             */
/*   Updated: 2021/05/05 15:36:46 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(const char *format)
{
	t_flags	flag;

	flag.minus = 0;
	flag.zero = 0;
	flag.dot = 0;
	flag.star = 0;
	flag.width = 0;
	flag.prec = 0;
	flag.len = 0;
	flag.neg = 0;
	flag.error = 0;
	flag.precerror = 0;
	flag.theformat = format;
	return (flag);
}

t_flags	is_flag(int input, t_flags *flags, va_list args, int pos)
{
	if (input == '-')
		ft_flag_minus(flags);
	else if (input == '*')
		ft_flag_star(args, flags);
	else if (input == '0' && flags->width == 0 && flags->minus == 0)
		flags->zero = 1;
	else if (input == '.')
		ft_flag_dot(flags->theformat, flags, args, pos);
	if (ft_isdigit(input) && flags->dot != 1)
		ft_flag_digit(input, flags);
	return (*flags);
}

int	ft_allcount(char input, va_list args, t_flags flags)
{
	int	cnt;

	cnt = 0;
	if (input == 'c')
		cnt = ft_char(va_arg(args, int), flags);
	else if (input == 's')
		cnt += ft_str(va_arg(args, char *), flags);
	else if (input == 'p')
		cnt += ft_pointer(va_arg(args, unsigned long), flags);
	else if (input == 'd' || input == 'i')
		cnt += ft_int(va_arg(args, int), flags);
	else if (input == 'u' || input == 'x' || input == 'X')
		cnt += ft_unint_hexa(input, va_arg(args, unsigned int), flags);
	else if (input == '%')
		cnt += ft_percent(flags);
	return (cnt);
}
