/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:56:53 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/06 16:22:52 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_bool		ft_is_resolution(char *line)
{
	while (*line == ' ' && *(line + 1) != '\0')
		line++;
	return (*line == 'R' && *(line + 1) == ' ');
}

t_bool		ft_is_texture(char *line)
{
	while (*line == ' ' && *(line + 2) != '\0')
		line++;
	return ((*line == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ') ||
			(*line == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ') ||
			(*line == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ') ||
			(*line == 'E' && *(line + 1) == 'A' && *(line + 2) == ' '));
}

t_bool		ft_is_sprite(char *line)
{
	while (*line == ' ' && *(line + 1) != '\0')
		line++;
	return (*line == 'S' && *(line + 1) == ' ');
}

t_bool		ft_is_color(char *line)
{
	while (*line == ' ' && *(line + 1) != '\0')
		line++;
	return ((*line == 'F' && *(line + 1) == ' ') ||
			(*line == 'C' && *(line + 1) == ' '));
}

t_bool		ft_is_map(char *line)
{
	while (*line != '\0')
	{
		if (*line != '1' || *line != ' ' ||
			*line != '2' || *line != '0')
			return (0);
		line++;
	}
	return (1);
}
