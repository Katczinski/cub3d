/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:04:52 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/11 19:13:29 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

//ft_atoi
//ft_strlen

void	skip_spaces(char **line)
{
	while (**line == ' ')
		(*line)++;
}

char	*trim_path(char *path)
{
	int		len;
	char	*res;

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

char	*save_line(char *s)
{
	char	*res;
	int		i;

	i = 0;
	res = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while ((res[i] = s[i]))
		i++;
	res[i] = '\0';
	return (res);
}

int		lines_count(char **map)
{
	int i;

	i = 0;
	while (map && map[i])
		i++;
	return (i);
}

char	**join_map(char **map, char *line)
{
	char	**res;
	int		i;
	int		lines;

	i = 0;
	lines = lines_count(map);
//	printf("line in join_map = |%s|\n", line);
	if (!(res = (char**)malloc(sizeof(char*) * (lines + 2))))
		return (0);
	while (map && (res[i] = map[i]))
		i++;
	res[i] = save_line(line);
	res[++i] = 0;
	free(map);
	return (res);
}
