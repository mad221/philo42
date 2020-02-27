/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:23:54 by mpouzol           #+#    #+#             */
/*   Updated: 2020/02/25 16:02:25 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	isblank(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ');
}

static int	ind(char c, const char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	ft_is_num(const char *str)
{
	int i;

	i = 0;
	if (str[0] == '-' || str[0] == '0')
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

static int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_atoi_base(const char *nptr, const char *base)
{
	int		result;
	int		neg;
	int		blen;

	result = 0;
	blen = ft_strlen(base);
	if (ft_is_num(nptr) == -1)
		return (-1);
	while (isblank(*nptr))
		nptr++;
	neg = *nptr == '-';
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (ind(*nptr, base) < blen)
		result = result * blen - ind(*nptr++, base);
	return (neg ? result : -result);
}
