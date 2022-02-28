/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:16:39 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/14 12:16:51 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_a_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->status->forks[philo->lfrk]);
	pthread_mutex_lock(&philo->status->forks[philo->rfrk]);
	status_msg(philo->status, philo->id, FORK);
	status_msg(philo->status, philo->id, FORK);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->status->lock_eat);
	philo->last_meal = get_time();
	status_msg(philo->status, philo->id, EATING);
	pthread_mutex_unlock(&philo->status->lock_eat);
	philo->p_eating++;
	wait_handler(philo->status->time_eat, philo->last_meal, philo);
	if (philo->p_eating == philo->status->n_time_eat)
	{
		status_msg(philo->status, philo->id, SATISFY);
		philo->status->philo_ate = 1;
	}
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->status->forks[philo->lfrk]);
	pthread_mutex_unlock(&philo->status->forks[philo->rfrk]);
}

void	sleeping(t_philo *philo)
{
	long long	start;

	start = get_time();
	status_msg(philo->status, philo->id, SLEEPING);
	wait_handler(philo->status->time_sleep, start, philo);
}

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (!philo->status->dead)
	{
		if (philo->status->quantity == 1)
		{
			one_philo_death(philo);
			break ;
		}
		take_a_fork(philo);
		eating(philo);
		drop_forks(philo);
		if (philo->status->philo_ate)
			break ;
		sleeping(philo);
		status_msg(philo->status, philo->id, THINKING);
	}
	return (NULL);
}
