/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:43:10 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/14 12:01:23 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	exit_program(char *txt)
{
	ft_putstr_fd(txt, 1);
	exit(1);
}

void	exit_code(int type)
{
	if (type == -1)
		exit_program("<Error: Invalid number of args>\n");
	else if (type == -2)
		exit_program("<Error: Invalid input in args>\n");
	else if (type == -3)
		exit_program("<Error: Value not allowed>\n");
	else if (type == -4)
		exit_program("There is no philosopher sit\n");
	else if (type == -5)
		exit_program("All Philosophers are satisfied already\n");
}
