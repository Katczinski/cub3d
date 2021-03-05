/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:56:53 by abirthda          #+#    #+#             */
/*   Updated: 2021/02/19 16:47:34 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_bool		ft_is_resolution(char *line)
{
	skip_spaces(&line);
	return (*line == 'R' && ft_is_ws(*(line + 1)));
}

t_bool		ft_is_texture(char *line)
{
	skip_spaces(&line);
	return ((*line == 'N' && *(line + 1) == 'O' && ft_is_ws(*(line + 2))) ||
			(*line == 'S' && *(line + 1) == 'O' && ft_is_ws(*(line + 2))) ||
			(*line == 'W' && *(line + 1) == 'E' && ft_is_ws(*(line + 2))) ||
			(*line == 'E' && *(line + 1) == 'A' && ft_is_ws(*(line + 2))));
}

t_bool		ft_is_sprite(char *line)
{
	skip_spaces(&line);
	return (*line == 'S' && ft_is_ws(*(line + 1)));
}

t_bool		ft_is_color(char *line)
{
	skip_spaces(&line);
	return ((*line == 'F' && ft_is_ws(*(line + 1))) ||
			(*line == 'C' && ft_is_ws(*(line + 1))));
}

t_bool		ft_is_empty(char *line)
{
	while (*line != '\0')
	{
		if (!ft_is_ws(*line))
			return (0);
		line++;
	}
	return (1);
}
