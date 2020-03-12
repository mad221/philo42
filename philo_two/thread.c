/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:27:29 by mpouzol           #+#    #+#             */
/*   Updated: 2020/03/12 14:46:00 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long		ft_get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int				ft_set_value(t_philo *philo, t_info *info, sem_t *s, sem_t *e)
{
	philo->philo_total = info->number;
	philo->time_eat = info->time_eat;
	philo->time_sleep = info->time_sleep;
	philo->time_die = info->time_die + 1;
	philo->rest_bf_die = ft_get_time();
	philo->semaphore = s;
	philo->speak = e;
	philo->begin = ft_get_time();
	philo->eat = info->eat;
	return (0);
}

void			*ft_live(void *arg)
{
	t_philo *philo;

	philo = (t_philo*)arg;
	while (1)
	{
		if (ft_eat(philo) == 1)
			if (ft_sleep(philo) == 1)
				ft_think(philo);
	}
}

void			ft_thread(t_philo *philo, t_info *info)
{
	int i;

	i = 0;
	while (i < info->number)
	{
		pthread_create(&philo[i].thread, NULL, ft_live, &philo[i]);
		i++;
		usleep(50);
	}
}

int				ft_threading(t_info *info)
{
	t_philo			*philo;
	sem_t			*semaphore;
	sem_t			*speak;
	struct timeval	before;
	int				i;

	i = 0;
	speak = sem_open("speak", O_CREAT, 0644, 1);
	semaphore = sem_open("sem", O_CREAT, 0644, info->number);
	if (!(speak) || !(semaphore))
		return (0);
	if (!(philo = malloc(sizeof(t_philo) * info->number)))
		return (0);
	while (i < info->number)
	{
		ft_set_value(&philo[i], info, semaphore, speak);
		philo[i].number = i;
		i++;
	}
	gettimeofday(&before, NULL);
	ft_thread(philo, info);
	ft_is_dead(philo, info);
	return (0);
}
