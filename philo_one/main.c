/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:00:09 by mpouzol           #+#    #+#             */
/*   Updated: 2020/02/24 16:01:17 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info *info;

	if (!(info = malloc(sizeof(t_info))))
		return (0);
	if (ac == 5)
	{
		if (ft_parsing(info, av) == 0)
			return (0);
		ft_threading(info);
	}
	return (0);
}
