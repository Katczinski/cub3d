/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:35:59 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/14 17:45:44 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	*settings_error(int status)
{
	char *log;

	(status == 1) ? log = "Invalid line: " : 0;
	(status == 2) ? log = "Invalid resolution (too many arguments): " : 0;
	(status == 3) ? log = "Unexpected characters in resolution line: " : 0;
	(status == 4) ? log = "Invalid resolution (too few arguments): " : 0;
	(status == 5) ? log = "Resolution is specified twice: " : 0;
	(status == 6) ? log = "Texture path is specified twice: " : 0;
	(status == 7) ? log = "Texture path is invalid: " : 0;
	(status == 8) ? log = "Unexpected characters in color line" : 0;
	(status == 9) ? log = "Invalid color (too many arguments)" : 0;
	(status == 10) ? log = "Invalid color in floor/ceiling line " : 0;
	return (log);
}

char	*map_error(int status)
{
	char *log;

	log = 0;
	(status == 11) ? log = "Map must be surrounded by walls" : 0;
	(status == 12) ? log = "Unexpected character in map" : 0;
	(status == 13) ? log = "Multiple player's start positions" : 0;
	(status == 14) ? log = "No player on the map" : 0;
	return (log);
}

char	*missing_parameter(int status)
{
	char *log;

	log = 0;
	(status == 15) ? log = "Resolution is missing" : 0;
	(status == 16) ? log = "NO texture is missing" : 0;
	(status == 17) ? log = "EA texture is missing" : 0;
	(status == 18) ? log = "WE texture is missing" : 0;
	(status == 19) ? log = "SO texture is missing" : 0;
	(status == 20) ? log = "Sprite texture is missing" : 0;
	(status == 21) ? log = "Floor color is missing" : 0;
	(status == 22) ? log = "Ceiling color is missing" : 0;
	(status == 23) ? log = "No player on the map" : 0;
	(status == 24) ? log = "Map is missing" : 0;
	return (log);
}

int		throw_error(int status)
{
	char		*log;
	static int	flag;

	if (flag)
		return (-1);
	flag = 1;
	log = 0;
	ft_putstr_fd("Error:\n", 2);
	if (1 <= status && status <= 10)
		log = settings_error(status);
	else if (status >= 11 && status <= 14)
		log = map_error(status);
	else if (status == 0)
	{
		ft_putstr_fd("Malloc failure\n", 2);
		return (0);
	}
	else if (status >= 15 && status <= 24)
		log = missing_parameter(status);
	ft_putstr_fd(log, 2);
	write(2, "\n", 1);
	return (-1);
}
