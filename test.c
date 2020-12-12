/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:54:03 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/12 16:28:14 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(void)
{
	int	fd;
	int	i = 0;
	t_params *res;

	fd = open("map.cub", O_RDONLY);
	res = parsecub(fd);
	if (res)
	{
		printf("width = %d\nheight = %d\n", res->width, res->height);
	
		printf("NO texture = |%s|\n", res->no);
		printf("SO texture = |%s|\n", res->so);
		printf("WE texture = |%s|\n", res->we);
		printf("EA texture = |%s|\n", res->ea);
		printf("Sprite texture = |%s|\n", res->sprite);
		printf("RGB value for floor = |%d|%d|%d|\n", res->floor->r, res->floor->g, res->floor->b);
		printf("RGB value for ceilling = |%d|%d|%d|\n", res->ceilling->r, res->ceilling->g, res->ceilling->b);
		printf("map:\n");
		while (res->map && res->map[i])
		{
			printf("|%s|\n", res->map[i]);
			i++;
		}
	}
	else
		printf("An error has occured");
	if(res)
		ft_free(res);
	close(fd);

	return (0);
}
