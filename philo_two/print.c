/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:27:10 by mpouzol           #+#    #+#             */
/*   Updated: 2020/02/29 11:29:53 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long long nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}

void	ft_print(char *str, t_philo *philo)
{
	if (philo->eat != 0)
	{
		sem_wait(philo->speak);
		ft_putnbr(ft_get_time() - philo->begin);
		ft_putstr(" philo ");
		ft_putnbr(philo->number + 1);
		ft_putstr(str);
		if (philo->is_dead != 1)
			sem_post(philo->speak);
	}
}
