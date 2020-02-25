/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:27:18 by mpouzol           #+#    #+#             */
/*   Updated: 2020/02/24 15:24:01 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			ft_sleep(t_philo *philo)
{
	sem_wait(philo->speak);
	ft_print(" is sleeping \n", philo);
	sem_post(philo->speak);
	usleep(philo->time_sleep * 1000);
	return (1);
}

int			ft_think(t_philo *philo)
{
	sem_wait(philo->speak);
	ft_print(" is thinking \n", philo);
	sem_post(philo->speak);
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
			ft_print(" is dead \n", philo);
			stop = 1;
		}
		i++;
	}
}
