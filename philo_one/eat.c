/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:54:28 by mpouzol           #+#    #+#             */
/*   Updated: 2020/02/27 16:23:26 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex[philo->philo_total]);
	ft_print(" has taken a fork\n", philo);
	pthread_mutex_unlock(&philo->mutex[philo->philo_total]);
}

void	ft_eat2(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex[philo->number]);
	ft_take_fork(philo);
	pthread_mutex_lock(&philo->mutex[0]);
	ft_take_fork(philo);
	pthread_mutex_lock(&philo->mutex[philo->philo_total]);
	philo->rest_bf_die = ft_get_time();
	if (philo->eat != -1)
		philo->eat--;
	ft_print(" is eating\n", philo);
	pthread_mutex_unlock(&philo->mutex[philo->philo_total]);
	usleep(philo->time_eat * 1000);
	pthread_mutex_unlock(&philo->mutex[0]);
	pthread_mutex_unlock(&philo->mutex[philo->number]);
}

int		ft_eat(t_philo *philo)
{
	if (philo->number == philo->philo_total - 1)
		ft_eat2(philo);
	else
	{
		pthread_mutex_lock(&philo->mutex[philo->number]);
		ft_take_fork(philo);
		pthread_mutex_lock(&philo->mutex[philo->number + 1]);
		ft_take_fork(philo);
		pthread_mutex_lock(&philo->mutex[philo->philo_total]);
		philo->rest_bf_die = ft_get_time();
		if (philo->eat != -1)
			philo->eat--;
		ft_print(" is eating\n", philo);
		pthread_mutex_unlock(&philo->mutex[philo->philo_total]);
		usleep(philo->time_eat * 1000);
		pthread_mutex_unlock(&philo->mutex[philo->number + 1]);
		pthread_mutex_unlock(&philo->mutex[philo->number]);
	}
	return (1);
}
