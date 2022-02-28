/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:32:15 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/14 12:28:32 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_and_clean(t_philo *philo, t_status *status)
{
	int	i;

	i = -1;
	while (++i < status->quantity)
	{
		pthread_join(philo[i].t_id, NULL);
		pthread_mutex_destroy(&status->forks[i]);
	}
	pthread_mutex_destroy(&status->lock_msg);
	pthread_mutex_destroy(&status->lock_eat);
	pthread_mutex_destroy(&status->lock_dead);
	free(status->philos);
	free(status->forks);
}

void	create_and_join(t_status *status)
{
	int		i;
	t_philo	*philo;

	philo = status->philos;
	philo->status->initial_time = get_time();
	i = -1;
	while (++i < status->quantity)
	{
		pthread_create(&philo[i].t_id, NULL, routine, &philo[i]);
		philo[i].last_meal = get_time();
	}
	philo_death(philo);
	join_and_clean(philo, status);
}

int	main(int argc, char **argv)
{
	t_status	status;
	int			i;

	i = -1;
	if (!(argc == 5 || argc == 6))
		exit_code(-1);
	if (!check_args(argv, argc))
		exit_code(-2);
	get_status(argv, argc, &status);
	create_and_join(&status);
	return (0);
}
