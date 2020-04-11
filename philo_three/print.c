/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:27:10 by mpouzol           #+#    #+#             */
/*   Updated: 2020/02/29 11:30:17 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
	sem_wait(philo->speak);
	ft_putnbr(ft_get_time() - philo->begin);
	write(1, " philo ", 7);
	ft_putnbr(philo->number + 1);
	write(1, str, ft_strlen(str));
	if (philo->is_dead != 1)
		sem_post(philo->speak);
}
