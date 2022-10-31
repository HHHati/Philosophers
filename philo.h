/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:20:23 by bade-lee          #+#    #+#             */
/*   Updated: 2022/10/31 13:04:39 by bade-lee         ###   ########.fr       */
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
# define E_ARGS_SIZE 33

# define MSG_FORK "has taken a fork\n"
# define MSG_EAT "is eating\n"
# define MSG_THINK "is thinking\n"
# define MSG_SLEEP "is sleeping\n"
# define MSG_DIED "died\n"

//          ----------========== {    STRUCT    } ==========----------

typedef struct s_info
{
	long long		start_time;
	int				i;
	int				number;
	int				time_eat;
	int				time_sleep;
	int				time_death;
	int				max_eat;
	int				dead;
	int				*times_eat;
	long long		*last_eat;
	pthread_t		*philo;
	pthread_t		check;
	pthread_mutex_t	*fork;
	pthread_mutex_t	lock;
}				t_info;

//          ----------========== {     FCTS     } ==========----------

void		init_info(t_info *info, int argc, char **argv);
void		take_fork(t_info *info, int philo);
void		eat(t_info *info, int philo);
void		let_fork(t_info *info, int philo);
void		sleeping(t_info *info, int philo);
int			check_status(t_info *info);
void		write_line(t_info *info, int philo, char *line);
long long	get_time(void);
long long	get_relative_time(t_info *info);
void		wait_time(int time, t_info *info);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);

#endif