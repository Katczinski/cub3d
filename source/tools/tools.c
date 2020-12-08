/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:04:52 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/07 17:15:45 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

//ft_atoi
//ft_strlen

char	*trim_path(char *path)
{
	int		len;
	char 	*res;
	
	while (*path == ' ')
		path++;
	len = ft_strlen(path);
	while (path[len - 1] == ' ')
		len--;
	if (path[len - 1] != 'm' || path[len - 2] != 'p' ||
		path[len - 3] != 'x' || path[len - 4] != '.')
		return (0);
	res = (char*)malloc(sizeof(char) * (len + 1));
	res[len] = '\0';
	while (len > 0)
	{	
		res[len - 1] = path[len - 1];
		len--;
	}
	return (res);
}
