/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:56:53 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/04 15:35:30 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_bool		ft_is_resolution(char *line)
{
	return (line[0] == 'R' && line[1] == ' ');
}

t_bool		ft_is_texture(char *line)
{
	return ((line[0] == 'N' && line[1] == 'O' && line[2] == ' ') ||
			(line[0] == 'S' && line[1] == 'O' && line[2] == ' ') ||
			(line[0] == 'W' && line[1] == 'E' && line[2] == ' ') ||
			(line[0] == 'E' && line[1] == 'A' && line[2] == ' '));
}

t_bool		ft_is_sprite(char *line)
{
	return (line[0] == 'S' && line[1] == ' ');
}

t_bool		ft_is_floor(char *line)
{
	return (line[0] == 'F' && line[1] == ' ');
}

t_bool		ft_is_ceilling(char *line)
{
	return (line[0] == 'C' && line[1] == ' ');
}
