/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:20:36 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/06 16:23:09 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int		check_line(char *line, t_params *cub)
{
	if (ft_is_resolution(line))
		return (handle_resolution(line, cub));
	else if (ft_is_texture(line))
		return (handle_texture(line, cub));
/*	else if (ft_is_sprite(line))
		return (handle_sprite(line, cub));
	else if (ft_is_color(line))
		return (handle_color(line, cub));
	else if (ft_is_map(line))
		return (1);
	else if (line == 0)
		return (0);
*/	else
		return (1); //throw invalid line

}

t_params	*parsecub(int fd)
{
	t_params	*cub;
	char		*line;
	int			ret;

	if (!(cub = (t_params*)malloc(sizeof(t_params))))
		return (0); //throw error
	ft_init(cub);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((check_line(line, cub)) < 0)
		{
//			ft_free(cub); //also need to free the buff inside gnl somehow;
//			free(cub);
//			free(line);
			return (0);
		}
		free(line);
		line = 0;
	}

	return (cub);
}
