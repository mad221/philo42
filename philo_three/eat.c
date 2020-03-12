/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:11:10 by mpouzol           #+#    #+#             */
/*   Updated: 2020/03/12 12:53:57 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_kill(int *pid, t_info *info, t_philo *philo)
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

void	ft_close_sem(sem_t *sp, sem_t *sem, sem_t *exit, sem_t *eat)
{
	sem_close(sp);
	sem_close(sem);
	sem_close(exit);
	sem_close(eat);
}

void	ft_take_fork(t_philo *philo)
{
	sem_wait(philo->speak);
	ft_print(" has taken a fork\n", philo);
	sem_post(philo->speak);
}

int		ft_eat(t_philo *philo)
{
	sem_wait(philo->semaphore);
	ft_take_fork(philo);
	sem_wait(philo->semaphore);
	ft_take_fork(philo);
	philo->rest_bf_die = ft_get_time();
	sem_wait(philo->speak);
	ft_print(" is eating\n", philo);
	sem_post(philo->speak);
	usleep(philo->time_eat * 1000);
	if (philo->eat != -1)
		philo->eat--;
	sem_post(philo->semaphore);
	sem_post(philo->semaphore);
	return (1);
}
