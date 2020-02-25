/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:44:39 by mpouzol           #+#    #+#             */
/*   Updated: 2020/02/24 15:52:31 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHILO_H
# define _PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct	s_info
{
	int			number;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	long long	before;
	long long	after;
}				t_info;

typedef struct	s_philo
{
	int			number;
	int			time_die;
	long long	rest_bf_die;
	int			time_eat;
	int			time_sleep;
	int			philo_total;
	long long	begin;
	sem_t		*semaphore;
	sem_t		*speak;
	pthread_t	thread;
}				t_philo;

void			ft_is_dead(t_philo *philo, t_info *info, struct timeval before);
int				ft_think(t_philo *philo);
int				ft_sleep(t_philo *philo);
int				ft_eat(t_philo *philo);
int				ft_threading(t_info *info);
int				ft_parsing(t_info *info, char **av);
int				ft_atoi_base(const char *nptr, const char *base);
long long		ft_get_time(void);
void			ft_print(char *str, t_philo *philo);
void			ft_thread(t_philo *philo, t_info *info);
void			ft_unlink(void);

#endif
