/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:37:19 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/14 17:25:28 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void		ft_free_textures(t_params *cub)
{
	free(cub->no);
	free(cub->so);
	free(cub->we);
	free(cub->ea);
	free(cub->sprite);
}

t_params	*ft_free(t_params *cub)
{
	int i;

	i = 0;
	free(cub->floor);
	free(cub->ceiling);
	free(cub->player);
	ft_free_textures(cub);
	if (cub->map)
	{
		while (cub->map[i])
		{
			free(cub->map[i]);
			cub->map[i] = 0;
			i++;
		}
		free(cub->map);
	}
	free(cub);
	return (0);
}

t_params	*ft_free_gnl(char **line, int fd, t_params *cub)
{
	int ret;

	ft_free(cub);
	free(*line);
	*line = 0;
	while ((ret = get_next_line(fd, line)) > 0)
	{
		free(*line);
		*line = 0;
	}
	free(*line);
	return (0);
}
