/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:12:48 by bmachado          #+#    #+#             */
/*   Updated: 2021/05/05 16:14:50 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	va_list	args;
	t_flags	flags;

	va_start(args, format);
	i = 0;
	j = 0;
	while (format[i])
	{
		flags = ft_init_flags(format);
		if (format[i] == '%')
		{
			i++;
			flags.pos = i;
			while (!(ft_strchr(ALLSYM, format[i])))
				is_flag(format[i++], &flags, args, flags.pos);
			j += ft_allcount(format[i], args, flags);
		}
		else
			j += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (j);
}
