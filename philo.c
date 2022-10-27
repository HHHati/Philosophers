/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:20:28 by bade-lee          #+#    #+#             */
/*   Updated: 2022/10/27 21:45:54 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_loop(void *args)
{
	t_info		*info;
	static int	number;
	int			new_number;

	info = (t_info *)args;
	pthread_mutex_lock(&info->lock);
	number += 1;
	new_number = number;
	pthread_mutex_unlock(&info->lock);
	if ((new_number % 2) == 1)
		wait_time(info->time_eat / 2, info);
	if (info->number == 1)
	{
		take_fork(info, new_number);
		wait_time(info->time_death, info);
		let_fork(info, new_number);
	}
	while (!check_status(info))
	{
		take_fork(info, new_number);
		eat(info, new_number);
		let_fork(info, new_number);
		sleeping(info, new_number);
	}
	return (0);
}

static void	*monitor(void *args)
{
	t_info		*info;
	int			i;

	info = (t_info *)args;
	while (1 == 1)
	{
		i = 0;
		while (i < info->number)
		{
			pthread_mutex_lock(&info->lock);
			if(info->time_death <= (get_time() - info->last_eat[i]))
			{
				info->dead = 1;
				printf("%lli    %i %s", get_relative_time(info), i + 1, MSG_DIED);
			}
			pthread_mutex_unlock(&info->lock);
			if (check_status(info))
				return (0);
			i++;
		}
	}
	return (0);
}

static int	check_args(int argc, char **argv)
{
	int i;
	int n;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		write(2, E_ARGS, E_ARGS_SIZE);
		return (0);
	}
	while (argv[i])
	{
		n = 0;
		while (argv[i][n])
		{
			if (!ft_isdigit(argv[i][n]))
			{
				write(2, E_ARGS, E_ARGS_SIZE);
				return (0);
			}
			n++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (!check_args(argc, argv))
		return (1);
	init_info(&info, argc, argv);
	pthread_create(&info.monitor, NULL, &monitor, (void *)&info);
	info.i = 0;
	while (info.i < info.number)
	{
		pthread_create(&info.philo[info.i], NULL, &philo_loop, (void *)&info);
		info.i++;
	}
	info.i = 0;
	while (info.i < info.number)
	{
		pthread_join(info.philo[info.i], NULL);
		pthread_mutex_destroy(&info.fork[info.i]);
		info.i++;
	}
	pthread_join(info.monitor, NULL);
	pthread_mutex_destroy(&info.lock);
	return (0);
}
