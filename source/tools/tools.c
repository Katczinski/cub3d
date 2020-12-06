/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:04:52 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/06 16:08:56 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	*trim_path(char *path)
{
	int		len;

	len = 0;
	while (*path == ' ' && *path != '\0')
		path++;
	len = ft_strlen(path);
	while (path[len] == ' ')
		len--;
	path[len + 1] = '\0';
	return (path);
}
