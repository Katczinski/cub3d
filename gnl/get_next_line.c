/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:46:51 by abirthda          #+#    #+#             */
/*   Updated: 2020/11/29 14:12:09 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char *buff;
	char		*tmp;
	int			bytes_read;

	bytes_read = 1;
	if (!line || fd < 0 || BUFFER_SIZE < 1 ||
		(!(tmp = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	if (read(fd, tmp, 0) == -1)
	{
		free(tmp);
		return (-1);
	}
	while (!check_buff(buff) && bytes_read)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		tmp[bytes_read] = '\0';
		buff = addtobuff(buff, tmp);
	}
	free(tmp);
	buff = addtoline(&line, buff);
	return (!(bytes_read == 0));
}
