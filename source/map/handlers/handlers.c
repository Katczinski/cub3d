/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 12:37:12 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/07 14:46:33 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int		handle_resolution(char *line, t_params *cub)
{
	while (*line == ' ')	
		line++;
	line++;
	while (*line != '\0')
	{
		while (*line == ' ')
		line++;
		if (!cub->width)
			cub->width = ft_atoi(line);
		else if (!cub->height)
			cub->height = ft_atoi(line);
		else
			return (-1); // throw error invalid resolution;
		while ('0' <= *line && *line <= '9')
			line++;
		while (*line == ' ')
			line++;
	}
	return ((cub->width > 0 && cub->height > 0) ? 1 : -1); //throw invalid resolution
}

int		handle_texture(char *line, t_params *cub)
{
	char *path;

	while (*line == ' ')
		line++;
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
		return (-1); //throw recurring path
	if ((open(path, O_RDONLY)) < 0)
		return (-1); //throw invalid path;
	return (1);
}

int		handle_sprite(char *line, t_params *cub)
{
	char *path;

	while (*line == ' ')
		line++;
	path = trim_path(line + 1);
	if (!cub->sprite)
		cub->sprite = path;	
	else
		return (-1); //throw recurring path
	if ((open(path, O_RDONLY)) < 0)
		return (-1); //throw invalid path;
	return (1);
}

int		handle_color(char *line, t_params *cub)
{
	while (*line == ' ')
		line++;
	return (1);	
}
