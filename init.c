/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:18:44 by bade-lee          #+#    #+#             */
/*   Updated: 2022/10/28 10:21:26 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_info(t_info *info, int argc, char **argv)
{
	info->i = 0;
	info->start_time = get_time();
	info->dead = 0;
	info->number = ft_atoi(argv[1]);
	info->time_death = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	info->max_eat = -1;
	if (argc == 6)
		info->max_eat = ft_atoi(argv[5]);
	info->last_eat = malloc(info->number * sizeof(long long));
	info->times_eat = malloc(info->number * sizeof(int));
	info->philo = (pthread_t *)malloc(info->number * sizeof(pthread_t));
	info->fork = (pthread_mutex_t *)malloc(info->number
			* sizeof(pthread_mutex_t));
	pthread_mutex_init(&info->lock, NULL);
	while (info->i < info->number)
	{
		info->last_eat[info->i] = info->start_time;
		info->times_eat[info->i] = 0;
		pthread_mutex_init(&info->fork[info->i], NULL);
		info->i++;
	}
	pthread_mutex_init(&info->fork[info->i], NULL);
}
