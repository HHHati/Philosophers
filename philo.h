/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:20:23 by bade-lee          #+#    #+#             */
/*   Updated: 2022/10/25 14:08:13 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//          ----------========== {   INCLUDES   } ==========----------

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

//          ----------========== {     DEFS     } ==========----------

# define E_ARGS "philosophers: invalid arguments\n"

# define MSG_FORK "has taken a fork\n"
# define MSG_EAT "is eating\n"
# define MSG_THINK "is sleeping\n"
# define MSG_SLEEP "is thinking\n"
# define MSG_DIED "died\n"

//          ----------========== {    STRUCT    } ==========----------

typedef struct l_philo
{
	int				number;
	int				mutex_count;
	long int		last_eat;
	pthread_t		thread;
	struct l_info	*info;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	fork2;
}				t_philo;

typedef struct l_info
{
	int				number;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				eat_max;
	int				philo_eat;
	int				stop;
	long int		start_time;
	t_philo			*philo;
	pthread_mutex_t	speak;
	pthread_mutex_t	mutex_stop;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	mutex_died;
}				t_info;

//          ----------========== {     FCTS     } ==========----------

int			init_info(t_info *info, char **argv);
int			init_philo(t_info *info);
void		*loop_philo(void *arg);
int			check_death(t_philo *philo, int n);
void		write_line(t_philo *philo, char *line);
void		big_free(t_info *info);
int			check_args(char **argv);
long long	get_time(void);
long long	get_relative_time(t_info *info);
void		wait_time(int time, t_info info);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);

#endif