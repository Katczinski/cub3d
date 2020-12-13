/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 15:24:46 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/13 13:38:02 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	*save_line(char *s, int len)
{
	char	*res;
	int		i;
	int		size;

	i = 0;
	size = len ? len : ft_strlen(s);
	res = (char*)malloc(sizeof(char) * (size + 1));
	while (s && s[i])
	{
		res[i] = s[i];
		i++;
	}
	while (i < len)
		res[i++] = ' ';
	res[i] = '\0';
	if (len)
		free(s);
	return (res);
}

int		longest_line(char **map)
{
	int cur;
	int max;
	int i;

	i = 0;
	cur = 0;
	max = 0;
	while (map[i])
	{
		cur = ft_strlen(map[i]);
		if (cur > max)
			max = cur;
		i++;
	}
	return (max);
}

char	**align_map(char **map)
{
	int	len;
	int	i;

	i = 0;
	len = longest_line(map);
	while (map[i])
	{
		map[i] = save_line(map[i], len);
		i++;
	}
	return (map);
}

char	**join_map(char **map, char *line)
{
	char		**res;
	int			i;
	static int	lines;

	i = 0;
//	lines = lines_count(map);
	if (!(res = (char**)malloc(sizeof(char*) * (lines++ + 2))))
		return (0);
	while (map && map[i])
	{
		res[i] = map[i];
		i++;
	}
	res[i] = save_line(line, 0);
	res[++i] = 0;
	if (map)
		free(map);
	return (res);
}
