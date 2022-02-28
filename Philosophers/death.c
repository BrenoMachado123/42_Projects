/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:52:55 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/14 12:28:39 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_any_philo_dead(t_philo *philo)
{
	long long	time_diff;

	time_diff = get_time() - philo->last_meal;
	if (time_diff > philo->status->time_die)
		return (1);
	return (0);
}

void	one_philo_death(t_philo *philo)
{
	status_msg(philo->status, philo->id, FORK);
	wait_handler(philo->status->time_die, get_time(), philo);
	status_msg(philo->status, philo->id, DEAD);
	philo->status->dead = 1;
}

void	philo_death(t_philo *philo)
{
	while (!philo->status->dead)
	{
		if (philo->status->philo_ate == 1)
			return ;
		pthread_mutex_lock(&philo->status->lock_eat);
		if (is_any_philo_dead(philo))
		{
			status_msg(philo->status, philo->id, DEAD);
			philo->status->dead = 1;
			pthread_mutex_unlock(&philo->status->lock_eat);
			usleep(100);
		}
		pthread_mutex_unlock(&philo->status->lock_eat);
	}
}
