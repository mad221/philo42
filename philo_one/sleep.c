/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:15:02 by mpouzol           #+#    #+#             */
/*   Updated: 2020/02/24 16:17:23 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex[philo->philo_total]);
	ft_print(" is sleeping \n", philo);
	pthread_mutex_unlock(&philo->mutex[philo->philo_total]);
	usleep(philo->time_sleep * 1000);
	return (1);
}

int			ft_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex[philo->philo_total]);
	ft_print(" is thinking \n", philo);
	pthread_mutex_unlock(&philo->mutex[philo->philo_total]);
	usleep(0);
	return (0);
}

long long	ft_diff_time(struct timeval after, struct timeval before)
{
	return (ft_get_time() - (before.tv_sec * 1000 + before.tv_usec / 1000));
}

void		ft_is_dead(t_philo *philo, t_info *info, struct timeval before)
{
	int				i;
	int				stop;
	struct timeval	after;

	stop = 0;
	i = 0;
	while (stop != 1)
	{
		if (i == info->number)
			i = 0;
		if (ft_get_time() - philo[i].rest_bf_die > philo[i].time_die)
		{
			pthread_mutex_lock(&philo->mutex[philo->philo_total]);
			ft_print(" is dead \n", philo);
			pthread_mutex_unlock(&philo->mutex[philo->philo_total]);
			stop = 1;
		}
		i++;
	}
}
