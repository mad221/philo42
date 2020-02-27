/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:03:41 by mpouzol           #+#    #+#             */
/*   Updated: 2020/02/27 16:25:43 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHILO_H
# define _PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct		s_info
{
	int				number;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	long long		before;
	long long		after;
	int				eat;
}					t_info;

typedef struct		s_philo
{
	int				number;
	int				eat;
	int				sleep;
	int				time_die;
	long long		rest_bf_die;
	int				time_eat;
	int				time_sleep;
	int				die;
	int				philo_total;
	long long		begin;
	pthread_mutex_t	*mutex;
	pthread_t		thread;
}					t_philo;

void				ft_is_dead(t_philo *philo, t_info *i);
int					ft_think(t_philo *philo);
int					ft_sleep(t_philo *philo);
int					ft_eat(t_philo *philo);
int					ft_threading(t_info *info);
int					ft_parsing(t_info *info, char **av, int ac);
int					ft_atoi_base(const char *nptr, const char *base);
long long			ft_get_time(void);
void				ft_print(char *str, t_philo *philo);

#endif
