/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:24:34 by bmachado          #+#    #+#             */
/*   Updated: 2021/05/05 15:46:26 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char const *str)
{
	size_t	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!(s) || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

static	void	putlong(long int n, int fd)
{
	if (n > 9)
		putlong(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd, t_flags flag)
{
	long int	v;

	v = n;
	if (v < 0)
	{
		v = -v;
		if (n != -2147483648)
			ft_putchar_fd('-', 1);
		else if (n == -2147483648 && flag.minus == 1)
			ft_putchar_fd('-', 1);
	}
	putlong(v, fd);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, sizeof(c));
}
