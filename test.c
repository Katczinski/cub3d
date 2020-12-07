/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:54:03 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/07 14:45:37 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int		main(void)
{
	int	fd;
	t_params *res;
	
	fd = open("map.cub", O_RDONLY);
	res = parsecub(fd);
	if (res)
	{
		printf("width = %d\nheight = %d\n", res->width, res->height);
	
		printf("NO texture = %s\n", res->no);
		printf("SO texture = %s\n", res->so);
		printf("WE texture = %s\n", res->we);
		printf("EA texture = %s\n", res->ea);
		printf("Sprite texture = %s\n", res->sprite);
	}
	else
		printf("An error has occured");
	ft_free(res);
	close(fd);
}
