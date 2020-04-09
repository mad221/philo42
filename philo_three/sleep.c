/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:27:18 by mpouzol           #+#    #+#             */
/*   Updated: 2020/03/04 20:00:43 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			ft_sleep(t_philo *philo)
{
	if (philo->eat != 0)
	{
		ft_print(" is sleeping \n", philo);
		usleep(philo->time_sleep * 1000);
		ft_print(" is thinking \n", philo);
		return (1);
	}
	return (0);
}

int			ft_all_eat(t_philo *philo)
{
	if (philo->eat == 0)
	{
		sem_post(philo->sem_eat);
		exit(1);
		return (0);
	}
	return (1);
}

void		*ft_dead(t_philo *philo, t_info *info)
{
	while (1)
	{
		if (ft_all_eat(philo) == 0)
			return (NULL);
		if (ft_get_time() - philo->rest_bf_die > philo->time_die)
		{
			ft_print(" is dead \n", philo);
			sem_wait(philo->speak);
			info->dead = 1;
			sem_post(philo->exit);
			return (NULL);
		}
	}
	return (NULL);
}
