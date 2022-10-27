/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:28:36 by bade-lee          #+#    #+#             */
/*   Updated: 2022/10/27 13:15:22 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_info *info, int philo)
{
	pthread_mutex_lock(&info->fork[(philo - 1)]);
	write_line(info, philo, MSG_FORK);
	if (philo == info->number)
		pthread_mutex_lock(&info->fork[0]);
	else
		pthread_mutex_lock(&info->fork[philo]);
	write_line(info, philo, MSG_FORK);
}

void	eat(t_info *info, int philo)
{
	write_line(info, philo, MSG_EAT);
	pthread_mutex_lock(&info->lock);
	info->last_eat[philo - 1] = get_time();
	if (info->max_eat >= 0)
		info->times_eat[philo - 1] += 1;
	pthread_mutex_unlock(&info->lock);
	wait_time(info->time_eat, info);
}

void	let_fork(t_info *info, int philo)
{
	pthread_mutex_unlock(&info->fork[(philo - 1)]);
	if (philo == info->number)
		pthread_mutex_unlock(&info->fork[0]);
	else
		pthread_mutex_unlock(&info->fork[philo]);
}

void	sleeping(t_info *info, int philo)
{
	write_line(info, philo, MSG_SLEEP);
	wait_time(info->time_sleep, info);
	write_line(info,philo, MSG_THINK);
}
