/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:23:26 by bade-lee          #+#    #+#             */
/*   Updated: 2022/10/24 16:07:24 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo, int n)
{
	pthread_mutex_lock(&philo->info->mutex_died);
	if (n)
		philo->info->stop = 1;
	if (philo->info->stop)
	{
		pthread_mutex_unlock(&philo->info->mutex_died);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->mutex_died);
	return (0);
}

void	write_line(t_philo *philo, char *line)
{
	long int	time;

	pthread_mutex_lock(&(philo->info->speak));
	time = get_time() - philo->info->start_time;
	if (!philo->info->stop && time >= 0 && time <= INT_MAX && !check_death(philo, 0))
		printf("%lld   %d %s", get_relative_time(philo->info), philo->number, line);
	pthread_mutex_unlock(&(philo->info->speak));
}