/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:42:22 by abirthda          #+#    #+#             */
/*   Updated: 2021/02/08 14:07:47 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int		ft_atoi(char *nptr)
{
	unsigned int	nbr;
	unsigned int	old_nbr;
	long			m;
	int				i;

	i = 0;
	nbr = 0;
	m = 1;
	while ((9 <= nptr[i] && nptr[i] <= 14) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			m *= -1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		old_nbr = nbr;
		nbr = nbr * 10 + nptr[i] - 48;
		i++;
		if (nbr > 2147483648 || old_nbr > nbr)
			return (m > 0 ? 2147483647 : -2147483648);
	}
	return ((int)nbr * m);
}
