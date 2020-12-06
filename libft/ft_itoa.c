/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:12:25 by abirthda          #+#    #+#             */
/*   Updated: 2020/11/03 16:37:00 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_size(int c)
{
	int	size;

	size = c <= 0 ? 1 : 0;
	while (c)
	{
		c /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int c)
{
	char	*res;
	long	nb;
	int		size;

	size = ft_size(c);
	nb = c;
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	res[size] = '\0';
	if (nb == 0)
	{
		res[0] = '0';
		return (res);
	}
	while (nb)
	{
		if (nb < 0)
		{
			res[0] = '-';
			nb *= -1;
		}
		res[size-- - 1] = nb % 10 + 48;
		nb /= 10;
	}
	return (res);
}
