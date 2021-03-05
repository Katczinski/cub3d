/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:10:41 by abirthda          #+#    #+#             */
/*   Updated: 2021/03/04 14:29:24 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_is_ws(char c)
{
	return ((9 <= c && c <= 14) || c == ' ');
}

void	skip_spaces(char **line)
{
	while (ft_is_ws(**line) && **line != '\0')
		(*line)++;
}

char	*trim_path(char *path)
{
	int		len;
	char	*res;

	skip_spaces(&path);
	len = ft_strlen(path);
	while (ft_is_ws(path[len - 1]))
		len--;
	if (path[len - 1] != 'm' || path[len - 2] != 'p' ||
		path[len - 3] != 'x' || path[len - 4] != '.')
	{
		throw_error(14);
		return (0);
	}
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
	{
		throw_error(0);
		return (0);
	}
	res[len++] = '\0';
	while (--len > 0)
		res[len - 1] = path[len - 1];
	return (res);
}

int		check_name(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len >= 4 &&
		name[len - 1] == 'b' &&
		name[len - 2] == 'u' &&
		name[len - 3] == 'c' &&
		name[len - 4] == '.')
		return (1);
	return (0);
}

int		check_args(int argc, char **argv, int *fd, int *save)
{
	if (argc == 2 || (argc == 3 && ((*save) = !(ft_strcmp(argv[2], "--save")))))
	{
		if (check_name(argv[1]))
		{
			(*fd) = open(argv[1], O_RDONLY);
			if ((*fd) < 0)
				return (throw_error(27));
		}
		else
			return (throw_error(26));
	}
	else
	{
		ft_putstr_fd("Error\n\n\
./cub3D <mapname.cub> - for game to run\n\
./cub3D <mapname.cub> --save - to create bmp\n\n", 2);
		return (-1);
	}
	return (1);
}
