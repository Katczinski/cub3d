/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:42:22 by abirthda          #+#    #+#             */
/*   Updated: 2020/11/02 13:43:33 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_atoi(const char *nptr)
{
	long	nbr;
	long	m;
	int		i;

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
		if (nbr > 2147483648 && nptr[i] > '7')
			return (m > 0 ? -1 : 0);
		nbr = nbr * 10 + nptr[i] - 48;
		i++;
	}
	return ((int)nbr * m);
}
