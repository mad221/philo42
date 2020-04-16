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

void	*ft_dead(t_philo *philo, t_info *info)
{
	int	i;
	int result;

	i = -1;
	while (1)
	{
		if (philo->eat != 0)
			if ((result = ft_get_time() - philo->rest_bf_die) > philo->time_die)
			{
				philo->is_dead = 1;
				info->dead = 1;
				ft_print_dead(" is dead \n", philo, result);
				if (philo->eat != -1)
					while (++i < philo->philo_total)
						sem_post(philo->sem_eat);
				sem_post(philo->exit);
				return (NULL);
			}
	}
	return (NULL);
}

void	ft_get_started(t_info *info, t_philo *philo, int i)
{
	int s;

	if (i == info->number)
	{
		s = 0;
		while (s < info->number)
		{
			sem_post(philo[s].start);
			s++;
		}
	}
}
