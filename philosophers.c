/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:03:29 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/03 19:39:42 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_args(int argc, char **argv)
{
	size_t	i;

	i = 1;
	if (!(argc == 5 || argc == 6))
		return (0);
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}

static int	init_info(t_philo *philo)
{
	size_t	i;

	philo->info = malloc(philo->number * sizeof(t_info));
	if (!philo->info)
		return (0);
	i = 0;
	while (i < philo->number)
	{
		philo->info[i].number = i;
		philo->info[i].time_die = philo->time_die;
		philo->info[i].time_eat = philo->time_eat;
		philo->info[i].time_sleep = philo->time_sleep;
		philo->info[i].fork1 = philo->mutex[i];
		if (i < philo->number - 1)
			philo->info[i].fork2 = philo->mutex[i + 1];
		else
			philo->info[i].fork2 = philo->mutex[0];
		i++;
	}
	return (1);
}

void	init_philo(int argc, char **argv, t_philo *philo)
{
	if (!check_args)
	{
		write(2, "philosophers: invalid arguments\n", 32);
		exit(1);
	}
	philo->number = ft_atoi(argv[1]);
	philo->time_die = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		philo->eat_max = 0;
	else
		philo->eat_max = ft_atoi(argv[5]);
	if (!init_info(philo))
	{
		write(2, "philosophers: allocation problem\n", 33);
		exit(1);
	}
	philo->threads = malloc(philo->number * sizeof(pthread_t *));
	if (!philo->threads)
	{
		write(2, "philosophers: allocation problem\n", 33);
		free(philo->info);
		exit(1);
	}
	philo->mutex = malloc(philo->number * sizeof(pthread_mutex_t *));
	if (!philo->mutex)
	{
		write(2, "philosophers: allocation problem\n", 33);
		free(philo->info);
		free(philo->threads);
		exit(1);
	}	
}

void	*loop_philo(void *arg)
{
	loooooop
}

void	philosophers(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->number)
	{
		pthread_mutex_init(philo->mutex[i], NULL);
		pthread_create(philo->threads[i], NULL, loop_philo, philo);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo			philo;
	pthread_mutex_t	speak;
	
	init_philo(argc, argv, philo);
	pthread_mutex_init(&speak, NULL);
	philosophers(&philo);
	pthread_mutex_destroy(&speak);
	return (0);
}
