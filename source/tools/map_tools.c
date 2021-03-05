/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 15:24:46 by abirthda          #+#    #+#             */
/*   Updated: 2021/02/19 15:36:23 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char		*save_line(char *s, int len)
{
	char	*res;
	int		i;
	int		size;

	i = 0;
	size = len ? len : ft_strlen(s);
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (s && s[i])
	{
		res[i] = s[i];
		i++;
	}
	while (i < len)
		res[i++] = ' ';
	res[i] = '\0';
	free(s);
	s = 0;
	return (res);
}

int			longest_line(char **map)
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

char		**align_map(char **map)
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

char		**join_map(t_params *cub, char *line)
{
	char		**res;
	int			i;
	static int	lines;

	i = 0;
	if (!(res = (char**)malloc(sizeof(char*) * (lines++ + 2))))
		return (0);
	while (cub->map && cub->map[i])
	{
		res[i] = cub->map[i];
		i++;
	}
	if (!(res[i] = save_line(line, 0)))
		return (0);
	res[++i] = 0;
	free(cub->map);
	cub->map_len = lines;
	return (res);
}

t_sprites	**join_sprites(t_params *cub, int y, int x)
{
	static int	sprites_num;
	int			i;
	t_sprites	**res;

	i = 0;
	if (!(res = (t_sprites**)malloc(sizeof(t_sprites*) * (sprites_num++ + 2))))
		return (0);
	while (cub->sprites && cub->sprites[i])
	{
		res[i] = cub->sprites[i];
		i++;
	}
	if (!(res[i] = (t_sprites*)malloc(sizeof(t_sprites))))
		return (0);
	res[i]->x = (float)x + 0.5;
	res[i]->y = (float)y + 0.5;
	res[i]->dist = 0;
	res[++i] = 0;
	cub->sprites_num = sprites_num;
	free(cub->sprites);
	return (res);
}
