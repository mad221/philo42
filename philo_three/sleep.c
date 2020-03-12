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
		sem_wait(philo->speak);
		ft_print(" is sleeping \n", philo);
		sem_post(philo->speak);
		usleep(philo->time_sleep * 1000);
		return (1);
	}
	usleep(philo->time_sleep * 1000);
	return (0);
}

int			ft_think(t_philo *philo)
{
	sem_wait(philo->speak);
	ft_print(" is thinking \n", philo);
	sem_post(philo->speak);
	usleep(0);
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

void		*ft_dead(t_philo *philo)
{
	while (1)
	{
		if (ft_get_time() - philo->rest_bf_die > philo->time_die)
		{
			sem_wait(philo->speak);
			ft_print(" is dead \n", philo);
			sem_post(philo->exit);
			exit(1);
		}
		if (ft_all_eat(philo) == 0)
			return (NULL);
	}
	return (NULL);
}
