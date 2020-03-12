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

int	main(int ac, char **av)
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
