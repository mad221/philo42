/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:27:29 by mpouzol           #+#    #+#             */
/*   Updated: 2020/03/12 12:55:58 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_live(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->eat != 0)
			if (ft_eat(philo) == 1 && philo->eat != 0)
				ft_sleep(philo);
	}
	return (NULL);
}

void	ft_time_eat_bf(t_philo *philo, t_info *info)
{
	int i;

	i = 0;
	sem_wait(philo[i].exit);
	if (info->eat != -1)
		while (i < info->number)
		{
			sem_wait(philo->sem_eat);
			i++;
		}
}

void	ft_time_eat_af(t_philo *philo, t_info *info)
{
	int i;

	i = -1;
	if (philo->eat != -1 && info->dead != 1)
	{
		while (++i < info->number)
			sem_wait(philo->sem_eat);
		sem_wait(philo->speak);
		sem_post(philo->exit);
	}
	if (info->dead == 1)
		sem_post(philo->exit);
}

int		*ft_processing(t_philo *philo, t_info *info)
{
	int i;
	int *pid;

	i = 0;
	if (!(pid = malloc(sizeof(int) * info->number)))
		return (0);
	ft_time_eat_bf(philo, info);
	while (i < info->number)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			pthread_create(&philo[i].thread, NULL, ft_live, &philo[i]);
			ft_dead(&philo[i], info);
		}
		i++;
	}
	ft_time_eat_af(philo, info);
	sem_wait(philo->exit);
	ft_kill(pid, info, philo);
	return (pid);
}

int		ft_process(t_info *info, t_philo *philo)
{
	sem_t	*se;
	sem_t	*sp;
	sem_t	*e;
	sem_t	*eat;
	int		i;

	i = -1;
	if (!(e = sem_open("exit", O_CREAT, 0644, 1)) ||
		!(sp = sem_open("speak", O_CREAT, 0644, 1)) ||
		!(se = sem_open("sem", O_CREAT, 0644, info->number)) ||
		!(eat = sem_open("eat", O_CREAT, 0644, info->number)) ||
		!(philo = malloc(sizeof(t_philo) * info->number)))
		return (0);
	while (++i < info->number)
	{
		ft_set_value(&philo[i], info);
		ft_set_sem(&philo[i], se, sp, e);
		philo[i].sem_eat = eat;
		philo[i].number = i;
		philo[i].begin = ft_get_time();
		philo[i].rest_bf_die = ft_get_time();
	}
	ft_processing(philo, info);
	ft_close_sem(sp, se, e, eat);
	return (0);
}
