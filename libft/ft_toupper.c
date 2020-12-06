/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:39:20 by abirthda          #+#    #+#             */
/*   Updated: 2020/10/30 14:39:22 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_toupper(int c)
{
	return ('a' <= c && c <= 'z' ? c - 32 : c);
}