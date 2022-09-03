/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:00:41 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/03 16:30:22 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//          ----------========== {   INCLUDES   } ==========----------

# include <unistd.h>

//          ----------========== {     DEFS     } ==========----------

//          ----------========== {    STRUCT    } ==========----------

typedef struct s_philo
{
	int	number;
	int time_die;
	int	time_eat;
	int	time_sleep;
	int	eat_max;
}				t_philo;

//          ----------========== {     FCTS     } ==========----------


#endif