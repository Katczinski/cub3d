/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:35:59 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/14 14:59:13 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int		throw_error(t_params *cub, char *line, int status)
{
	char *log;

	if (cub)
		;
	ft_putstr_fd("Error:\n", 2);
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
	ft_putstr_fd(log, 2);
	ft_putstr_fd(line, 2);
	write(2, "\n", 1);
	return (-1);
}
