/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:26:41 by mpouzol           #+#    #+#             */
/*   Updated: 2020/02/24 15:18:41 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_parsing(t_info *info, char **av)
{
	if ((info->number = ft_atoi_base(av[1], "0123456789")) == -1)
		return (0);
	if ((info->time_die = ft_atoi_base(av[2], "0123456789")) == -1)
		return (0);
	if ((info->time_eat = ft_atoi_base(av[3], "0123456789")) == -1)
		return (0);
	if ((info->time_sleep = ft_atoi_base(av[4], "0123456789")) == -1)
		return (0);
	return (1);
}
