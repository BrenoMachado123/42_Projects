/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:15:23 by bmachado          #+#    #+#             */
/*   Updated: 2021/05/04 15:19:10 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent(t_flags flags)
{
	int	count;

	count = 1;
	if (flags.minus == 1)
		ft_putchar_fd('%', 1);
	count += ft_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		ft_putchar_fd('%', 1);
	return (count);
}
