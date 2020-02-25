/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:04:50 by mpouzol           #+#    #+#             */
/*   Updated: 2020/02/24 18:46:40 by mpouzol          ###   ########.fr       */
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
	if (ac == 5)
	{
		if (ft_parsing(info, av) == 0)
			return (0);
		ft_process(info);
	}
	ft_unlink();
	free(info);
	return (0);
}
