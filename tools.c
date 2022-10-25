/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:31:48 by bade-lee          #+#    #+#             */
/*   Updated: 2022/10/25 14:07:10 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	big_free(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number)
	{
		pthread_mutex_destroy(info->philo[i].fork1);
		pthread_mutex_destroy(&info->philo[i].fork2);
		i++;
	}
	free(info->philo);
	pthread_mutex_destroy(&info->speak);
	pthread_mutex_destroy(&info->mutex_died);
	pthread_mutex_destroy(&info->mutex_eat);
	pthread_mutex_destroy(&info->mutex_stop);
}

int	check_args(char **argv)
{
	size_t	i;
	size_t	n;

	i = 1;
	while (argv[i])
	{
		n = 0;
		while (argv[i][n])
		{
			if (!ft_isdigit(argv[i][n]))
				return (1);
			n++;
		}
		i++;
	}
	return (0);
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

void	wait_time(int time, t_info info)
{
	int	reach_time;

	reach_time = get_relative_time(&info) + time;
	while (get_relative_time(&info) < reach_time)
		usleep(100);
}
