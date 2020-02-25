/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:11:10 by mpouzol           #+#    #+#             */
/*   Updated: 2020/02/24 15:40:02 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_philo *philo)
{
	sem_wait(philo->semaphore);
	sem_wait(philo->semaphore);
	philo->rest_bf_die = ft_get_time();
	sem_wait(philo->speak);
	ft_print(" is eating\n", philo);
	sem_post(philo->speak);
	usleep(philo->time_eat * 1000);
	sem_post(philo->semaphore);
	sem_post(philo->semaphore);
	return (1);
}
