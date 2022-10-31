/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:18:44 by bade-lee          #+#    #+#             */
/*   Updated: 2022/10/31 11:16:44 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_info_3(t_info *info)
{
	info->fork = (pthread_mutex_t *)malloc(info->number
			* sizeof(pthread_mutex_t));
	if (!info->fork)
	{
		free(info->last_eat);
		free(info->times_eat);
		free(info->philo);
		return ;
	}
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

static void	init_info_2(t_info *info)
{
	info->last_eat = malloc(info->number * sizeof(long long));
	if (!info->last_eat)
		return ;
	info->times_eat = malloc(info->number * sizeof(int));
	if (!info->times_eat)
	{
		free(info->last_eat);
		return ;
	}
	info->philo = (pthread_t *)malloc(info->number * sizeof(pthread_t));
	if (!info->philo)
	{
		free(info->last_eat);
		free(info->times_eat);
		return ;
	}
	init_info_3(info);
}

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
	init_info_2(info);
}
