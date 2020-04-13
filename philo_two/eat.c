/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:11:10 by mpouzol           #+#    #+#             */
/*   Updated: 2020/03/12 11:25:45 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_fork(t_philo *philo)
{
	sem_wait(philo->speak);
	ft_print(" has taken a fork\n", philo);
	sem_post(philo->speak);
}

int		ft_eat(t_philo *philo)
{
	sem_wait(philo->semaphore);
	sem_wait(philo->semaphore);
	ft_take_fork(philo);
	ft_take_fork(philo);
	philo->rest_bf_die = ft_get_time();
	sem_wait(philo->speak);
	ft_print(" is eating\n", philo);
	sem_post(philo->speak);
	usleep(philo->time_eat * 1000);
	sem_post(philo->semaphore);
	sem_post(philo->semaphore);
	if (philo->eat != -1)
		philo->eat--;
	return (1);
}
