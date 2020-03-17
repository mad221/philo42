/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:04:50 by mpouzol           #+#    #+#             */
/*   Updated: 2020/03/12 14:27:08 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			ft_unlink(void)
{
	sem_unlink("speak");
	sem_unlink("sem");
	sem_unlink("exit");
	sem_unlink("eat");
}

void			ft_set_sem(t_philo *philo, sem_t *s, sem_t *e, sem_t *q)
{
	philo->semaphore = s;
	philo->speak = e;
	philo->exit = q;
}

int				ft_set_value(t_philo *philo, t_info *info)
{
	philo->philo_total = info->number + 1;
	philo->time_eat = info->time_eat;
	philo->time_sleep = info->time_sleep;
	philo->time_die = info->time_die + 1;
	philo->rest_bf_die = ft_get_time();
	philo->begin = ft_get_time();
	philo->eat = info->eat;
	info->dead = 0;
	return (0);
}

long long		ft_get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int				main(int ac, char **av)
{
	t_info	*info;
	t_philo *philo;

	ft_unlink();
	if (!(info = malloc(sizeof(t_info))) ||
	!(philo = malloc(sizeof(t_philo))))
		return (0);
	if (ac == 5 || ac == 6)
	{
		if (ft_parsing(info, av, ac) == 0)
			return (0);
		if (info->number > 1)
			ft_process(info, philo);
	}
	ft_unlink();
	free(info);
	free(philo);
	return (0);
}
