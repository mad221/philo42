/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:27:29 by mpouzol           #+#    #+#             */
/*   Updated: 2020/02/26 15:25:40 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			*ft_live(void *arg)
{
	t_philo	*philo;
	int		stop;

	stop = 1;
	philo = (t_philo*)arg;
	while (stop == 1)
	{
		if (ft_eat(philo) == 1)
			if (ft_sleep(philo) == 1)
				ft_think(philo);
	}
	return (NULL);
}

int				*ft_processing(t_philo *philo, t_info *info, int *pid)
{
	int i;

	i = 0;
	sem_wait(philo[i].exit);
	while (i < info->number)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			pthread_create(&philo[i].thread, NULL, ft_live, &philo[i]);
			ft_dead(&philo[i]);
		}
		i++;
	}
	sem_wait(philo[1].exit);
	ft_kill(pid, info, philo);
	return (pid);
}

void			ft_kill(int *pid, t_info *info, t_philo *philo)
{
	int i;

	i = 0;
	while (i < info->number)
	{
		kill(pid[i], SIGKILL);
		i++;
	}
	free(philo);
}

void			ft_close_sem(sem_t *speak, sem_t *semaphore, sem_t *exit)
{
	sem_close(speak);
	sem_close(semaphore);
	sem_close(exit);
}

int				ft_process(t_info *info, t_philo *philo)
{
	sem_t			*se;
	sem_t			*sp;
	sem_t			*e;
	int				i;
	int				*pid;

	if (!(pid = malloc(sizeof(int) * info->number)))
		return (0);
	i = -1;
	if (!(e = sem_open("exit", O_CREAT, 0644, 1)) ||
	(!(sp = sem_open("speak", O_CREAT, 0644, 1)) ||
	(!(se = sem_open("sem", O_CREAT, 0644, info->number)))))
		return (0);
	if (!(philo = malloc(sizeof(t_philo) * info->number)))
		return (0);
	while (++i < info->number)
	{
		ft_set_value(&philo[i], info);
		ft_set_sem(&philo[i], se, sp, e);
		philo[i].number = i;
	}
	ft_processing(philo, info, pid);
	ft_close_sem(sp, se, e);
	return (0);
}
