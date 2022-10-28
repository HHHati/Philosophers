/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:04:21 by bade-lee          #+#    #+#             */
/*   Updated: 2022/10/28 10:23:04 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_status(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&info->lock);
	if (info->dead == 1)
	{
		pthread_mutex_unlock(&info->lock);
		return (1);
	}
	while (i < info->number)
	{
		if (info->times_eat[i] < info->max_eat || info->max_eat == -1)
		{
			pthread_mutex_unlock(&info->lock);
			return (0);
		}
		i++;
	}
	pthread_mutex_unlock(&info->lock);
	return (1);
}

void	write_line(t_info *info, int philo, char *line)
{
	long long	time;

	if (check_status(info))
		return ;
	pthread_mutex_lock(&info->lock);
	time = get_time() - info->start_time;
	if (!info->dead && time >= 0 && time <= INT_MAX)
		printf("%lli    %i %s", time, philo, line);
	pthread_mutex_unlock(&info->lock);
}

long long	get_time(void)
{
	struct timeval	tp;
	int				result;

	gettimeofday(&tp, NULL);
	result = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	return (result);
}

long long	get_relative_time(t_info *info)
{
	struct timeval	tp;
	int				result;

	gettimeofday(&tp, NULL);
	result = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	result -= info->start_time;
	return (result);
}

void	wait_time(int time, t_info *info)
{
	int	reach_time;

	reach_time = get_relative_time(info) + time;
	while (get_relative_time(info) < reach_time)
		usleep(100);
}
