/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:17:52 by mpouzol           #+#    #+#             */
/*   Updated: 2020/02/24 16:23:25 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t		*ft_mutex(int max)
{
	int				i;
	pthread_mutex_t	*mutex;

	i = 0;
	if (!(mutex = malloc(sizeof(pthread_mutex_t) * (max + 1))))
		return (0);
	while (i <= max)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	return (mutex);
}

long long			ft_get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int					ft_set_value(t_philo *philo, t_info *info, int i,
pthread_mutex_t *mutex)
{
	philo->number = i;
	philo->philo_total = info->number;
	philo->time_eat = info->time_eat;
	philo->time_sleep = info->time_sleep;
	philo->time_die = info->time_die + 5;
	philo->rest_bf_die = ft_get_time();
	philo->mutex = mutex;
	philo->begin = ft_get_time();
	return (0);
}

void				*ft_live(void *arg)
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

int					ft_threading(t_info *info)
{
	t_philo			*philo;
	pthread_mutex_t *mutex;
	struct timeval	before;
	int				i;

	i = 0;
	mutex = ft_mutex(info->number);
	if (!(philo = malloc(sizeof(t_philo) * info->number)))
		return (0);
	while (i < info->number)
	{
		ft_set_value(&philo[i], info, i, mutex);
		i++;
	}
	gettimeofday(&before, NULL);
	i = 0;
	while (i < info->number)
	{
		pthread_create(&philo[i].thread, NULL, ft_live, &philo[i]);
		i++;
	}
	ft_is_dead(philo, info, before);
	return (0);
}
