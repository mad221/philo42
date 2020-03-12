/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:04:50 by mpouzol           #+#    #+#             */
/*   Updated: 2020/03/12 14:56:31 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_unlink(void)
{
	sem_unlink("speak");
	sem_unlink("sem");
}

int		main(int ac, char **av)
{
	t_info	*info;

	ft_unlink();
	if (!(info = malloc(sizeof(t_info))))
		return (0);
	if (ac == 5 || ac == 6)
	{
		if (ft_parsing(info, av, ac) == 0)
			return (0);
		ft_threading(info);
	}
	free(info);
	ft_unlink();
	return (0);
}
