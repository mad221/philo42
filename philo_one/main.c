/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:00:09 by mpouzol           #+#    #+#             */
/*   Updated: 2020/03/12 14:59:52 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start_init(t_philo *philo, t_info *info)
{
	int				i;
	pthread_mutex_t	start;

	i = 0;
	pthread_mutex_init(&start, NULL);
	while (i < info->number)
	{
		philo[i].start = start;
		i++;
	}
}

void	ft_lets_go(t_philo *philo, t_info *info)
{
	int i;

	i = 0;
	while (i > info->number)
	{
		pthread_mutex_unlock(&philo[i].start);
		usleep(15);
		i++;
	}
}

int		main(int ac, char **av)
{
	t_info *info;

	if (!(info = malloc(sizeof(t_info))))
		return (0);
	if (ac == 5 || ac == 6)
	{
		if (ft_parsing(info, av, ac) == 0)
			return (0);
		ft_threading(info);
	}
	free(info);
	return (0);
}
