/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:30:13 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/12 16:45:36 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_bool		ft_is_map(char *line)
{
	while (*line != '\0')
	{
		if (*line != '1' && *line != '2' && *line != '0' &&
			*line != ' ' && *line != 'S' && *line != 'W' &&
			*line != 'E' && *line != 'N')
			return (0);
		line++;
	}
	return (1);
}

int			ft_check_edge(char *line, int last, char **map)
{
	int	lines;
	int	i;

	i = 0;
	lines = lines_count(map);
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '1')
			return (-1); // map must be surrounded by walls
		if (last)
		{
			if (line[i] == ' ' && (map[lines - 2][i] != '1' &&
									map[lines - 2][i] != ' '))
				return (-1); // map must be surrounded by walls
		}
		i++;
	}
	return (1);
}
