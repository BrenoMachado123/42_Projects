/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:58:45 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/14 12:15:34 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	status_action(int action)
{
	if (action == EATING)
		ft_putstr_fd(" is eating <<\n", 1);
	else if (action == SLEEPING)
		ft_putstr_fd(" is sleeping <<\n", 1);
	else if (action == FORK)
		ft_putstr_fd(" has taken a fork <<\n", 1);
	else if (action == THINKING)
		ft_putstr_fd(" is thinking <<\n", 1);
	else if (action == DEAD)
		ft_putstr_fd(" is dead <<\n", 1);
	else if (action == SATISFY)
		ft_putstr_fd(" is satisfied <<\n", 1);
}

void	wait_handler(long long t_act, long long start, t_philo *philo)
{
	while (get_time() - start < t_act)
	{
		if (is_any_philo_dead(philo))
		{
			philo->status->dead = 1;
			break ;
		}
		usleep(100);
	}
}

void	status_msg(t_status *status, int id, int action)
{
	pthread_mutex_lock(&status->lock_msg);
	if (!status->dead)
	{
		ft_putnbr_fd(get_time() - status->initial_time, 1);
		ft_putstr_fd(" >> Philosopher ", 1);
		ft_putnbr_fd(id + 1, 1);
		status_action(action);
	}
	pthread_mutex_unlock(&status->lock_msg);
}
