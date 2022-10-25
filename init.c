/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:41:29 by bade-lee          #+#    #+#             */
/*   Updated: 2022/10/25 14:12:27 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_info(t_info *info, char **argv)
{
	pthread_mutex_init(&info->speak, NULL);
	pthread_mutex_init(&info->mutex_died, NULL);
	pthread_mutex_init(&info->mutex_eat, NULL);
	pthread_mutex_init(&info->mutex_stop, NULL);
	info->stop = 0;
	info->philo = malloc(info->number * sizeof(t_philo));
	if (!info->philo)
		return (2);
	if (check_args(argv))
	{
		write(2, E_ARGS, 32);
		return (1);
	}
	info->philo_eat = 0;
	info->number = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		info->eat_max = ft_atoi(argv[5]);
	if (argv[5] && info->eat_max == 0)
		return (1);
	return (0);
}

int	init_philo(t_info *info)
{
	int	i;

	i = 0;
	info->start_time = get_time();
	while (i < info->number)
	{
		info->philo[i].number = i;
		info->philo[i].last_eat = 0;
		info->philo[i].fork1 = NULL;
		info->philo[i].info = info;
		info->philo[i].mutex_count = 0;
		pthread_mutex_init(&(info->philo[i].fork2), NULL);
		if (i == info->number - 1)
			info->philo[i].fork1 = &info->philo[0].fork2;
		else
			info->philo[i].fork1 = &info->philo[i + 2].fork2;
		if (pthread_create(&info->philo[i].thread, NULL, &loop_philo,
				&(info->philo[i])) != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i < info->number)
	{
		if (pthread_join(info->philo[i].thread, NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}
