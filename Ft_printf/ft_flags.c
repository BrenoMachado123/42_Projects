/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:40:00 by bmachado          #+#    #+#             */
/*   Updated: 2021/05/05 15:31:39 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_flag_digit(int c, t_flags *flags)
{
	if (flags->star == 1)
		flags->width = 0;
	flags->width = (flags->width * 10) + (c - '0');
	return (*flags);
}

t_flags	ft_flag_minus(t_flags *flags)
{
	flags->minus = 1;
	flags->zero = 0;
	return (*flags);
}

t_flags	ft_flag_star(va_list args, t_flags *flags)
{
	flags->star = 1;
	if (!(flags->dot))
		flags->width = va_arg(args, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= -1;
	}
	return (*flags);
}

int	ft_flag_dot(const char *format, t_flags *flags, va_list args, int pos)
{
	int	i;

	flags->dot = 1;
	i = pos;
	while (format[i])
	{
		if (ft_strchr(ALLSYM, format[i]))
			break ;
		if (format[i - 1] == '.' && ft_isdigit(format[i]))
		{
			while (ft_isdigit(format[i]))
				flags->prec = (flags->prec * 10) + (format[i++] - '0');
		}
		if (format[i - 1] == '.' && format[i] == '*')
			flags->prec = va_arg(args, int);
		i++;
	}
	if (flags->prec < 0)
		flags->precerror = 1;
	return (i);
}
