/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:30:13 by abirthda          #+#    #+#             */
/*   Updated: 2021/02/19 15:50:40 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_bool		ft_is_map(char *line)
{
	int wall;

	wall = 0;
	while (*line != '\0')
	{
		if (*line != '1' && *line != '2' && *line != '0' &&
			*line != ' ' && *line != 'S' && *line != 'W' &&
			*line != 'E' && *line != 'N')
			return (0);
		else if (*line == '1')
			wall = 1;
		line++;
	}
	return (wall);
}

int			check_surrounding(char **map, int y, int x)
{
	if (map[y][x] == '0' || map[y][x] == '2')
	{
		if ((map[y - 1][x] == '0' || map[y - 1][x] == '1' ||
			map[y - 1][x] == '2') && (map[y][x + 1] == '2' ||
			map[y][x + 1] == '0' || map[y][x + 1] == '1'))
			return (1);
	}
	else if (map[y][x] == ' ')
	{
		if ((map[y - 1][x] == ' ' || map[y - 1][x] == '1') &&
			(map[y][x + 1] == ' ' || map[y][x + 1] == '1' ||
			map[y][x + 1] == '\0'))
			return (1);
	}
	else if (map[y][x] == '1')
		return (1);
	return (-1);
}

int			check_pos(t_params *cub, int y, int x, char c)
{
	if (c != 'N' && c != 'E' && c != 'S' && c != 'W')
	{
		if (c == '0' || c == '1' || c == ' ' || c == '2' || c == '\0')
			return (throw_error(11));
		return (throw_error(12));
	}
	if (cub->player->pos_x < 0 || cub->player->pos_y < 0)
	{
		cub->map[y][x] = '0';
		cub->player->pos_y = (float)y + 0.5;
		cub->player->pos_x = (float)x + 0.5;
		if (c == 'N')
			MDIR_Y = -1;
		else if (c == 'E')
			MDIR_X = 1;
		else if (c == 'S')
			MDIR_Y = 1;
		else
			MDIR_X = -1;
		MPLANE_X = MDIR_X == 0 ? 0.66 * (-MDIR_Y) : 0;
		MPLANE_Y = MDIR_Y == 0 ? 0.66 * (MDIR_X) : 0;
		return (1);
	}
	return (throw_error(13));
}

int			ft_check_edge(char *line, int last, t_params *cub)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '1')
		{
			if (line[i] == 'N' || line[i] == 'E' ||
				line[i] == 'S' || line[i] == 'W')
				return (cub->player->pos_y < 0 ?
						throw_error(11) : throw_error(13));
			else
				return (line[i] == '0' ? throw_error(11) : throw_error(12));
		}
		if (last)
		{
			if (line[i] == ' ' &&
				(cub->map[last - 1][i] != '1' &&
				cub->map[last - 1][i] != ' '))
				return (throw_error(11));
		}
		i++;
	}
	return (1);
}

int			ft_check_map_line(t_params *cub, int y)
{
	int		x;

	x = 0;
	if (y == 0 || y == cub->map_len - 1)
		return (ft_check_edge(cub->map[y], y, cub));
	while (cub->map[y][x] == ' ')
		x++;
	if (cub->map[y][x] != '1')
		return (throw_error(11));
	while (cub->map[y][x] != '\0' && y < cub->map_len)
	{
		if (cub->map[y][x] != '0' && cub->map[y][x] != '1' &&
			cub->map[y][x] != ' ' && cub->map[y][x] != '2')
			if (check_pos(cub, y, x, cub->map[y][x]) < 0)
				return (throw_error(12));
		if (check_surrounding(cub->map, y, x) < 0)
			if ((check_pos(cub, y, x + 1, cub->map[y][x + 1]) < 0))
				return (throw_error(11));
		if (cub->map[y][x] == '2')
			if (!(cub->sprites = join_sprites(cub, y, x)))
				return (throw_error(-1));
		x++;
	}
	return (1);
}
