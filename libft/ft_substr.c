/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:44:57 by abirthda          #+#    #+#             */
/*   Updated: 2020/11/09 15:03:47 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	size;
	size_t	slen;

	if (s == 0)
		return (0);
	slen = ft_strlen(s);
	size = slen - start < len ? slen - start : len;
	result = (char*)malloc(sizeof(char) * (size + 1));
	if (result && start < slen)
		ft_strlcpy(result, s + start, size + 1);
	return (result);
}
