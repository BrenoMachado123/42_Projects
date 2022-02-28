/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:10:48 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/29 16:40:16 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_values(t_status *status)
{
	status->quantity = 0;
	status->time_eat = 0;
	status->time_sleep = 0;
	status->time_die = 0;
	status->dead = 0;
	status->n_time_eat = -1;
	status->philo_ate = 0;
	status->initial_time = 0;
	status->forks = NULL;
	status->philos = NULL;
}

static void	mutex_init(t_status *status)
{
	int	i;

	i = -1;
	status->forks = malloc(sizeof(t_status *) * status->quantity);
	if (!status->forks)
		return ;
	while (++i < status->quantity)
		pthread_mutex_init(&status->forks[i], NULL);
	pthread_mutex_init(&status->lock_msg, NULL);
	pthread_mutex_init(&status->lock_eat, NULL);
	pthread_mutex_init(&status->lock_dead, NULL);
}

static void	init_philos(t_status *status)
{
	int	i;

	i = 0;
	status->philos = malloc(sizeof(t_philo) * (status->quantity));
	if (!status->philos)
		return ;
	while (i < status->quantity)
	{
		status->philos[i].id = i;
		status->philos[i].lfrk = i;
		status->philos[i].rfrk = (i + 1) % status->quantity;
		status->philos[i].p_eating = 0;
		status->philos[i].last_meal = 0;
		status->philos[i].status = status;
		i++;
	}
}

void	get_status(char **argv, int argc, t_status *status)
{
	init_values(status);
	status->quantity = ft_atoi(argv[1]);
	if (status->quantity == 0)
		exit_code(-4);
	status->time_die = ft_atoi(argv[2]);
	status->time_eat = ft_atoi(argv[3]);
	status->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		status->n_time_eat = ft_atoi(argv[5]);
	if (status->n_time_eat == 0)
		exit_code(-5);
	if (status->time_die <= 0
		|| status->time_eat <= 0
		|| status->time_sleep <= 0)
		exit_code(-3);
	mutex_init(status);
	init_philos(status);
}
