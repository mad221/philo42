/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:54:28 by mpouzol           #+#    #+#             */
/*   Updated: 2020/02/24 16:25:47 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_philo *philo)
{
	if (philo->number == philo->philo_total - 1)
	{
		pthread_mutex_lock(&philo->mutex[philo->number]);
		pthread_mutex_lock(&philo->mutex[0]);
		pthread_mutex_lock(&philo->mutex[philo->philo_total]);
		philo->rest_bf_die = ft_get_time();
		ft_print(" is eating\n", philo);
		pthread_mutex_unlock(&philo->mutex[philo->philo_total]);
		usleep(philo->time_eat * 1000);
		pthread_mutex_unlock(&philo->mutex[0]);
		pthread_mutex_unlock(&philo->mutex[philo->number]);
	}
	else
	{
		pthread_mutex_lock(&philo->mutex[philo->number]);
		pthread_mutex_lock(&philo->mutex[philo->number + 1]);
		pthread_mutex_lock(&philo->mutex[philo->philo_total]);
		philo->rest_bf_die = ft_get_time();
		ft_print(" is eating\n", philo);
		pthread_mutex_unlock(&philo->mutex[philo->philo_total]);
		usleep(philo->time_eat * 1000);
		pthread_mutex_unlock(&philo->mutex[philo->number + 1]);
		pthread_mutex_unlock(&philo->mutex[philo->number]);
	}
	return (1);
}
