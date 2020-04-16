/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:44:39 by mpouzol           #+#    #+#             */
/*   Updated: 2020/03/12 12:55:49 by mpouzol          ###   ########.fr       */
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
# include <sys/types.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>

typedef struct	s_info
{
	int			number;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	long long	before;
	long long	after;
	int			eat;
	int			dead;
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
	sem_t		*exit;
	sem_t		*sem_eat;
	sem_t		*start;
	pthread_t	thread;
	int			pid;
	int			eat;
	int			is_dead;
}				t_philo;

void			ft_print_dead(char *str, t_philo *philo, int result);
void			ft_get_started(t_info *info, t_philo *philo, int i);
void			*ft_dead(t_philo *philo, t_info *info);
int				ft_think(t_philo *philo);
int				ft_sleep(t_philo *philo);
int				ft_eat(t_philo *philo);
int				ft_process(t_info *info, t_philo *philo);
int				ft_parsing(t_info *info, char **av, int ac);
int				ft_atoi_base(const char *nptr, const char *base);
long long		ft_get_time(void);
void			ft_print(char *str, t_philo *philo);
void			ft_thread(t_philo *philo, t_info *info);
void			ft_unlink(void);
int				ft_set_value(t_philo *philo, t_info *info, int i);
void			ft_set_sem(t_philo *philo, sem_t *s, sem_t *e, sem_t *q);
void			ft_kill(int *pid, t_info *info, t_philo *philo);
void			ft_close_sem(sem_t *sp, sem_t *sem, sem_t *exit, sem_t *eat);
void			ft_kill(int *pid, t_info *info, t_philo *philo);

#endif
