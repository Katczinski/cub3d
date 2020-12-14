/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:54:03 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/14 14:46:07 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <string.h>
int		main(void)
{
	int	fd;
	int	i = 0;
	t_params *res;

	fd = open("map.cub", O_RDONLY);
	res = parsecub(fd);
	if (res)
	{
		printf("-----------------------------------\n");
		printf("width = |%d|\nheight = |%d|\n", res->width, res->height);
		printf("NO texture = |%s|\n", res->no);
		printf("SO texture = |%s|\n", res->so);
		printf("WE texture = |%s|\n", res->we);
		printf("EA texture = |%s|\n", res->ea);
		printf("Sprite texture = |%s|\n", res->sprite);
		printf("RGB value for floor = |%d|%d|%d|\n", res->floor->r, res->floor->g, res->floor->b);
		printf("RGB value for ceilling = |%d|%d|%d|\n", res->ceiling->r, res->ceiling->g, res->ceiling->b);
		printf("map:\n");
		printf("map length = |%d|\n", res->map_len);
		printf("player's position = [%d][%d]\nspawning orientation = %c\n",res->player->pos_x, res->player->pos_y, res->player->dir);
		while (res->map && res->map[i])
		{
			printf("|%2d|%s|\n",i, res->map[i]);
			i++;
		}
		printf("|--|");
		for (int c = strlen(res->map[0]); c > 0; c--)
			printf("-");
		printf("|\n");
		printf("\033[0;32m");
		printf("Valid file\n");
		printf("\033[0m");

	}
	else
	{
		printf("\033[0;31m");
		printf("An error has occured\n");
		printf("\033[0m");
	}
	if(res)
		ft_free(res);
	close(fd);
	return (0);
}
