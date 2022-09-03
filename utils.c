/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:03:26 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/03 18:31:44 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_iswhitespace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
		if (result > INT_MAX / 10 && str[i] - 48
			> (INT_MAX % 10) - (sign - 1) / 2)
			return (-1);
	}
	return (result * sign);
}

int	get_start_time(void)
{
	struct timeval	tp;
	int				result;

	gettimeofday(&tp, NULL);
	result = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	return (result);
}

int get_relative_time(t_info *info)
{
	int	result;
	struct timeval	tp;

	gettimeofday(&tp, NULL)
	result = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	result -= info->start_time;
	return (result);
}

void	wait_time(int time, t_info info)
{
	int	reach_time;

	reach_time = get_relative_time(info) + time;
	while (get_relative_time(info) < reach_time)
		usleep(100);
}