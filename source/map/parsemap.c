/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:20:36 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/12 16:42:46 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int			check_line(char **line, int fd, t_params *cub)
{
	if (ft_is_resolution(*line))
		return (handle_resolution(*line, cub));
	else if (ft_is_texture(*line))
		return (handle_texture(*line, cub));
	else if (ft_is_sprite(*line))
		return (handle_sprite(*line, cub));
	else if (ft_is_color(*line))
		return (handle_color(*line, cub));
	else if (ft_is_empty(*line))
		return (0);
	else if (ft_is_map(*line))
		return (handle_map(fd, line, cub));
	else
		return (-1); //!!!(-1) throw invalid line
}

t_params	*parsecub(int fd)
{
	t_params	*cub;
	char		*line;
	int			ret;

	if (!(cub = ft_init(cub)))
		return (0); //throw malloc failure;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((check_line(&line, fd, cub)) < 0)
			return (ft_free_gnl(&line, fd, cub));
		free(line);
	}
	free(line);
	return (cub);
}

//LEAKS
