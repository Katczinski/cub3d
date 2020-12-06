/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:54:03 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/06 15:57:32 by abirthda         ###   ########.fr       */
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
		printf("width = %d\nheight = %d\n", res->width, res->height);
	else
		printf("An error has occured");
	close(fd);
}
