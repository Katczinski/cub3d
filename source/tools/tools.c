/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:04:52 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/07 14:34:28 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	*trim_path(char *path)
{
	int		len;
	char 	*res;
	len = 0;
	while (*path == ' ' && *path != '\0')
		path++;
	len = ft_strlen(path);
	while (path[len] == ' ')
		len--;
	res = (char*)malloc(sizeof(char) * (len + 1));
	res[len + 1] = '\0';
	while (len >= 0)
	{	
		res[len] = path[len];
		len--;
	}
	return (res);
}
