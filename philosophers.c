/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:03:29 by Bade-lee          #+#    #+#             */
/*   Updated: 2022/09/03 16:36:58 by Bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	philo;
	
	if (!(argc == 5 || argc == 6))
	{
		write(2, "philosophers: invalid arguments\n", 32);
		return (1);
	}
}
