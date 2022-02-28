/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:41:47 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/29 16:40:59 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define EATING 1
# define FORK 2
# define THINKING 3
# define SLEEPING 4
# define DEAD 5
# define SATISFY 6

typedef struct s_philo
{
	int				id;
	int				lfrk;
	int				rfrk;
	int				p_eating;
	int				p_time;
	long long		last_meal;
	pthread_t		t_id;
	struct s_status	*status;
}				t_philo;

typedef struct s_status
{
	int				dead;
	int				quantity;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				n_time_eat;
	int				philo_ate;
	long long		initial_time;
	pthread_mutex_t	lock_msg;
	pthread_mutex_t	lock_dead;
	pthread_mutex_t	lock_sleep;
	pthread_mutex_t	lock_eat;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}				t_status;

void		*routine(void *arg);
void		get_status(char **argv, int argc, t_status *status);
void		wait_handler(long long time, long long start, t_philo *philo);
void		status_msg(t_status *status, int id, int action);
void		p_end(t_status *status, t_philo *philo);
void		exit_code(int type);
void		take_a_fork(t_philo *philo);
void		eating(t_philo *philo);
void		drop_forks(t_philo *philo);
void		sleeping(t_philo *philo);
void		ft_putnbr_fd(long long n, int fd);
void		ft_putstr_fd(char *str, int fd);
void		ft_putchar_fd(char c, int fd);
void		create_and_join(t_status *status);
void		philo_death(t_philo *philo);
void		one_philo_death(t_philo *philo);

int			ft_isdigit(int c);
int			valid_input(char *input);
int			check_args(char **argv, int argc);
int			is_any_philo_dead(t_philo *philo);
int			ft_atoi(const char *str);
size_t		ft_strlen(char const *str);
long long	get_time(void);

#endif
