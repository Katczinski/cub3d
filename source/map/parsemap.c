/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:20:36 by abirthda          #+#    #+#             */
/*   Updated: 2021/02/19 16:47:30 by abirthda         ###   ########.fr       */
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
	else if (ft_is_map(*line) && !cub->map_end)
		return (handle_map(fd, line, cub));
	else
		return (cub->map_end && ft_is_map(*line) ? throw_error(25) :
													throw_error(1));
}

t_params	*parsecub(int fd)
{
	t_params	*cub;
	char		*line;
	int			ret;
	int			valid;

	cub = 0;
	line = 0;
	if (!(cub = ft_init(cub)) && !throw_error(0))
		return (0);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((check_line(&line, fd, cub)) < 0)
			return (ft_free_gnl(&line, fd, cub));
		free(line);
		line = 0;
	}
	if ((valid = check_cub(cub, 1)) < 0)
		return (ft_free(cub));
	if (ret < 0 && !throw_error(0))
		return (0);
	free(line);
	line = 0;
	return (cub);
}
