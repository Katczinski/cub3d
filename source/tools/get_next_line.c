/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:46:51 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/12 13:27:56 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int		get_next_line(int fd, char **line)
{
	static char *buff;
	char		*tmp;
	int			bytes_read;

	bytes_read = 1;
	if (!line || fd < 0 || (!(tmp = (char*)malloc(sizeof(char) * (1024 + 1)))))
		return (-1);
	if (read(fd, tmp, 0) == -1)
	{
		free(tmp);
		return (-1);
	}
	while (!check_buff(buff) && bytes_read)
	{
		bytes_read = read(fd, tmp, 1024);
		tmp[bytes_read] = '\0';
		if ((buff = addtobuff(buff, tmp)) == 0)
		{
			free(tmp);
			return (-1);
		}
	}
	free(tmp);
	buff = addtoline(line, buff);
	return (!(bytes_read == 0));
}
