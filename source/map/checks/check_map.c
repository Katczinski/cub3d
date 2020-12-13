/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:30:13 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/13 17:14:09 by abirthda         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '1')
			return (-1); // map must be surrounded by walls
		if (last)
		{
			if (line[i] == ' ' && (map[last - 1][i] != '1' &&
									map[last - 1][i] != ' '))
				return (-1); // map must be surrounded by walls
		}
		i++;
	}
	return (1);
}

int			check_pos(t_params *cub, int x, int y, char c)
{
	if (c != 'N' && c != 'E' && c != 'S' && c != 'W')
		return (-1);
	if (cub->player->pos_x < 0 || cub->player->pos_y < 0)
	{
		cub->map[x][y] = '0';
		cub->player->pos_x = x;
		cub->player->pos_y = y;
		cub->player->dir = c;
		return (1);
	}
	return (-1);
}

int			check_surrounding(char **map, int x, int y)
{
	if (map[x][y] == '0' || map[x][y] == '2')
	{
		if ((map[x - 1][y] == '0' || map[x - 1][y] == '1' ||
			map[x - 1][y] == '2') && (map[x][y + 1] == '2' ||
			map[x][y + 1] == '0' || map[x][y + 1] == '1'))
			return (1);
	}
	else if (map[x][y] == ' ')
	{
		if ((map[x - 1][y] == ' ' || map[x - 1][y] == '1') &&
			(map[x][y + 1] == ' ' || map[x][y + 1] == '1' ||
			map[x][y + 1] == '\0'))
			return (1);
	}
	else if (map[x][y] == '1')
		return (1);
	else
		return (-1);
	return (-1);
}

int			ft_check_map_line(t_params *cub, int x)
{
	int		y;

	if (x == 0 || x == cub->map_len - 1)
		return (ft_check_edge(cub->map[x], x, cub->map));
	y = 0;
	while (cub->map[x][y] == ' ')
		y++;
	if (cub->map[x][y] != '1')
		return (-1); //map must be surrounded by walls
	while (cub->map[x][y] != '\0' && x < cub->map_len)
	{
		if (cub->map[x][y] != '0' && cub->map[x][y] != '1' &&
			cub->map[x][y] != ' ' && cub->map[x][y] != '2')
			if (check_pos(cub, x, y, cub->map[x][y]) < 0)
				return (-1); //invalid character ?
		if (check_surrounding(cub->map, x, y) < 0)
			if ((check_pos(cub, x, y + 1, cub->map[x][y + 1]) < 0))
				return (-1); // map must be surrounded by walls
		y++;
	}
	return (1);
}
