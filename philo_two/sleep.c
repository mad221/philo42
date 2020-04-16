/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:27:18 by mpouzol           #+#    #+#             */
/*   Updated: 2020/03/12 14:55:33 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			ft_sleep(t_philo *philo)
{
	ft_print(" is sleeping \n", philo);
	usleep(philo->time_sleep * 1000);
	ft_print(" is thinking \n", philo);
	return (1);
}

int			ft_all_eat(t_philo *philo, int nbr)
{
	int i;
	int s;

	s = 0;
	i = 0;
	while (i < nbr)
	{
		if (philo[i].eat == 0)
			s++;
		i++;
	}
	if (s == nbr)
	{
		sem_wait(philo->speak);
		return (1);
	}
	else
		return (0);
}

void		ft_is_dead(t_philo *philo, t_info *info)
{
	int				i;
	int				stop;

	stop = 0;
	i = 0;
	while (stop != 1)
	{
		if (i == info->number)
			i = 0;
		if (ft_all_eat(philo, info->number) == 1)
			return ;
		if (ft_get_time() - philo[i].rest_bf_die > philo[i].time_die + 5
		&& philo[i].eat != 0)
		{
			philo[i].is_dead = 1;
			ft_print(" is dead \n", &philo[i]);
			return ;
		}
		i++;
	}
}
