/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_situations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:17:08 by bmachado          #+#    #+#             */
/*   Updated: 2021/05/05 15:30:42 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dot_str(char *str, t_flags *flag)
{
	int		count;
	char	*newstr;

	count = 0;
	if (flag->error != 1 && flag->precerror != 1)
		newstr = ft_substr(str, 0, flag->prec);
	else
		newstr = str;
	if (flag->minus == 1)
	{
		ft_putstr_fd(newstr, 1);
		count += ft_width(flag->width, ft_strlen(newstr), 0);
	}
	else if (flag->minus == 0)
	{
		count += ft_width(flag->width, ft_strlen(newstr), 0);
		ft_putstr_fd(newstr, 1);
	}
	count += ft_strlen(newstr);
	if (flag->error != 1 && flag->precerror != 1)
		free(newstr);
	return (count);
}

int	ft_treat_dot_int(int n, t_flags flag)
{
	int	count;

	count = 0;
	if (flag.prec > flag.len)
	{
		count += ft_dotpreczero(flag);
		count += ft_width(flag.prec, flag.len, 1);
		ft_putnbr_fd(n, 1, flag);
		if (flag.prec < flag.width && flag.minus == 1)
			count += ft_width(flag.width, flag.prec, 0);
	}
	else if (flag.prec <= flag.len)
	{
		count += ft_dotpreczero(flag);
		count += ft_width(flag.prec, flag.len, 0);
		if (flag.error != 1)
			ft_putnbr_fd(n, 1, flag);
		if (flag.prec < flag.width && flag.minus == 1)
			count += ft_width(flag.width, flag.len, 0);
	}
	return (count);
}
