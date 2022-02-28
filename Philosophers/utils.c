/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:33:53 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/13 18:05:10 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	signal;
	int	i;
	int	n;

	i = 0;
	signal = 1;
	n = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		n = n * 10;
		n += (int)str[i] - '0';
		i++;
	}
	return (n * signal);
}

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	else
		return (0);
}

int	valid_input(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!ft_isdigit((input[i])))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!valid_input(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
