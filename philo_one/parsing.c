/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:02:55 by mpouzol           #+#    #+#             */
/*   Updated: 2020/02/27 16:19:56 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_parsing(t_info *info, char **av, int ac)
{
	if ((info->number = ft_atoi_base(av[1], "0123456789")) == -1)
		return (0);
	if ((info->time_die = ft_atoi_base(av[2], "0123456789")) == -1)
		return (0);
	if ((info->time_eat = ft_atoi_base(av[3], "0123456789")) == -1)
		return (0);
	if ((info->time_sleep = ft_atoi_base(av[4], "0123456789")) == -1)
		return (0);
	info->eat = -1;
	if (ac == 6)
	{
		if ((info->eat = ft_atoi_base(av[5], "0123456789")) == -1)
			return (0);
	}
	return (1);
}
