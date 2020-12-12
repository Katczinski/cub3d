/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:52:46 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/12 13:27:54 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int				check_buff(char *buff)
{
	int i;

	i = 0;
	if (buff == 0)
		return (0);
	while (buff[i] != '\0')
		if (buff[i++] == '\n')
			return (1);
	return (0);
}

char			*ft_free_buff(char *buff)
{
	free(buff);
	return (0);
}

char			*addtoline(char **line, char *buff)
{
	int		i;
	char	*crop;

	i = 0;
	crop = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (!((*line) = (char*)malloc(sizeof(char) * (i + 1))))
		return (ft_free_buff(buff));
	i = 0;
	while (buff[i] != '\n' && buff[i])
	{
		(*line)[i] = buff[i];
		i++;
	}
	(*line)[i] = '\0';
	if (buff[i] != '\0')
		crop = addtobuff(0, buff + i + 1);
	free(buff);
	return (crop);
}

char			*addtobuff(char *buff, char *tmp)
{
	char	*result;
	int		i;
	int		j;

	if (!(result = (char*)malloc(sizeof(char) *
					(ft_strlen(buff) + ft_strlen(tmp) + 1))))
		return (ft_free_buff(buff));
	i = 0;
	j = 0;
	while (buff && buff[i])
	{
		result[i] = buff[i];
		i++;
	}
	while (tmp[j] != '\0')
	{
		result[i + j] = tmp[j];
		j++;
	}
	result[i + j] = '\0';
	free(buff);
	buff = 0;
	return (result);
}
