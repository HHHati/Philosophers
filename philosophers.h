/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:00:41 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/03 19:00:17 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//          ----------========== {   INCLUDES   } ==========----------

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

//          ----------========== {     DEFS     } ==========----------

//          ----------========== {    STRUCT    } ==========----------

typedef struct s_info
{
	int				number;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				start_time;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
	pthread_mutex_t *speak;
}				t_info;

typedef struct s_philo
{
	int				number;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				eat_max;
	int				start_time;
	t_info			*info;
	pthread_t		**threads;
	pthread_mutex_t	**mutex;
}				t_philo;

//          ----------========== {     FCTS     } ==========----------

void	init_philo(int argc, char **argv, t_philo *philo);
int		check_args(int argc, char **argv);
int		ft_atoi(const char *str);
int		get_start_time(void);
int 	get_relative_time(t_info *info);
void	wait_time(int time, t_info info);





#endif