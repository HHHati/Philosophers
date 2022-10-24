/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:20:28 by bade-lee          #+#    #+#             */
/*   Updated: 2022/10/24 21:43:33 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*check_status(void *arg)
{
	t_philo *philo;

	philo =(t_philo *)arg;
	wait_time(philo->info->time_die + 1, *philo->info);
	pthread_mutex_lock(&philo->info->mutex_eat);
	pthread_mutex_lock(&philo->info->mutex_stop);
	if (!check_death(philo, 0) && get_time() - philo->last_eat >= (long)(philo->info->time_die))
	{
		pthread_mutex_unlock(&philo->info->mutex_eat);
		pthread_mutex_unlock(&philo->info->mutex_stop);
		write_line(philo, "died\n");
		check_death(philo, 1);
	}
	pthread_mutex_unlock(&philo->info->mutex_eat);
	pthread_mutex_unlock(&philo->info->mutex_stop);
	return (0);
}

static void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork2));
	write_line(philo, MSG_FORK);
	if (philo->info->number == 1)
	{
		wait_time(philo->info->time_die * 2, *philo->info);
		return ;
	}
	pthread_mutex_lock(philo->fork1);
	write_line(philo, MSG_FORK);
}

static void	eat(t_philo *philo)
{
	write_line(philo, MSG_EAT);
	pthread_mutex_lock(&(philo->info->mutex_eat));
	philo->last_eat = get_time();
	philo->mutex_count++;
	pthread_mutex_unlock(&(philo->info->mutex_eat));
	wait_time(philo->info->time_eat, *philo->info);
	pthread_mutex_unlock((philo->fork1));
	pthread_mutex_unlock(&(philo->fork2));
	write_line(philo, MSG_SLEEP);
	wait_time(philo->info->time_sleep, *philo->info);
	write_line(philo, MSG_THINK);
}

void	*loop_philo(void *arg)
{
	t_philo 	*philo;
	pthread_t	t;

	philo = (t_philo *)arg;
	if (philo->number % 2 == 0)
		wait_time(philo->info->time_eat / 10, *philo->info);
	while (!check_death(philo, 0))
	{
		pthread_create(&t, NULL, check_status, arg);
		take_fork(philo);
		eat(philo);
		pthread_detach(t);
		if (philo->mutex_count == philo->info->eat_max)
		{
			pthread_mutex_lock(&philo->info->mutex_stop);
			if (++philo->info->philo_eat == philo->info->number)
			{
				pthread_mutex_unlock(&philo->info->mutex_stop);
				check_death(philo, 2);
			}
			pthread_mutex_unlock(&philo->info->mutex_stop);
			return (0);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info info;

	if (!(argc == 5 || argc == 6))
	{
		write(2, E_ARGS, 32);
		return (0);
	}
	if (init_info(&info, argv) == 1)
	{
		free(info.philo);
		return(0);
	}
	init_philo(&info);
	big_free(&info);
}
