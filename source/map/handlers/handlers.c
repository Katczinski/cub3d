/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 12:37:12 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/14 14:59:05 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int		handle_resolution(char *line, t_params *cub)
{
	char *errlog;

	errlog = line;
	if (cub->width > 0 && cub->height > 0)
		return (throw_error(cub, errlog, 5));
	skip_spaces(&line);
	line++;
	while (*line != '\0')
	{
		skip_spaces(&line);
		if (*line != '\0' && (*line < '0' || *line > '9'))
			return (throw_error(cub, errlog, 3));
		if (cub->width < 0)
			cub->width = ft_atoi(line);
		else if (cub->height < 0)
			cub->height = ft_atoi(line);
		else
			return (throw_error(cub, errlog, 2));
		while ('0' <= *line && *line <= '9')
			line++;
		skip_spaces(&line);
	}
	return ((cub->width > 0 && cub->height > 0) ? 1 :
			throw_error(cub, errlog, 4));
}

int		handle_texture(char *line, t_params *cub)
{
	char	*path;
	int		ret;

	path = 0;
	skip_spaces(&line);
	path = trim_path(line + 2);
	if (*line == 'N' && *(line + 1) == 'O' && !cub->no)
		cub->no = path;
	else if (*line == 'S' && *(line + 1) == 'O' && !cub->so)
		cub->so = path;
	else if (*line == 'W' && *(line + 1) == 'E' && !cub->we)
		cub->we = path;
	else if (*line == 'E' && *(line + 1) == 'A' && !cub->ea)
		cub->ea = path;
	else
		return (throw_error(cub, line, 6));
	if (!path || (ret = (open(path, O_RDONLY))) < 0)
		ret = -1;
	close(ret);
	return (ret < 0 ? throw_error(cub, line, 7) : 1);
}

int		handle_sprite(char *line, t_params *cub)
{
	char	*path;
	int		ret;

	skip_spaces(&line);
	path = trim_path(line + 1);
	if (!cub->sprite)
		cub->sprite = path;
	else
		return (throw_error(cub, line, 6));
	if (!path || (ret = open(path, O_RDONLY)) < 0)
		ret = -1;
	close(ret);
	return (ret < 0 ? throw_error(cub, line, 7) : 1);
}

int		handle_color(char *line, t_params *cub)
{
	t_color *tmp;

	skip_spaces(&line);
	tmp = (*line++ == 'C' ? cub->ceiling : cub->floor);
	while (*line != '\0')
	{
		skip_spaces(&line);
		if (*line != '\0' && (*line < '0' || *line > '9'))
			return (throw_error(cub, 0, 8));
		if (tmp->r < 0)
			tmp->r = ft_atoi(line);
		else if (tmp->g < 0)
			tmp->g = ft_atoi(line);
		else if (tmp->b < 0)
			tmp->b = ft_atoi(line);
		else
			return (throw_error(cub, 0, 9));
		while ('0' <= *line && *line <= '9')
			line++;
		skip_spaces(&line);
		line = (*line == ',') && (tmp->b < 0) ? line + 1 : line;
	}
	return ((tmp->r < 256 && tmp->g < 256 && tmp->b < 256) &&
			(tmp->r >= 0 && tmp->g >= 0 && tmp->b >= 0) ? 1 :
			throw_error(cub, 0, 10));
}

int		handle_map(int fd, char **line, t_params *cub)
{
	int i;

	i = 0;
	cub->map = join_map(cub, *line);
	free(*line);
	*line = 0;
	while (get_next_line(fd, line) && !ft_is_empty(*line))
	{
		cub->map = join_map(cub, *line);
		free(*line);
		*line = 0;
	}
	cub->map = align_map(cub->map);
	while (cub->map[i])
	{
		if (ft_check_map_line(cub, i) < 0)
			return (-1);
		i++;
	}
	return (1);
}
