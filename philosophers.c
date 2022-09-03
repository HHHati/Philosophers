/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:03:29 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/03 17:57:31 by Bade-lee         ###   ########.fr       */
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
}

int	main(int argc, char **argv)
{
	t_philo	philo;
	
	init_philo(argc, argv, philo);

	return (0);
}
