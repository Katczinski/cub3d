/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 14:55:03 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/22 17:05:05 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_vars *vars, int x, int y, int color)
{
	int j;
	int i;

	i = 0;
	while (i + (x * 10) < (x * 10) + 10)
	{
		j = 0;
		while (j + (y * 10) < (y * 10) + 10)
		{
			my_mlx_pixel_put(vars->img, (y * 10) + j, (x * 10) + i, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_vars *vars)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (vars->cub->map[y])
	{
		x = 0;
		while (vars->cub->map[y][x])
		{
			if (vars->cub->map[y][x] == '1')
				draw_square(vars, y, x, 0x00FF0000);
			else
				draw_square(vars, y, x, 0x00000000);
			x++;
		}
		y++;
	}
}

void	draw_player(t_vars *vars)
{
	my_mlx_pixel_put(vars->img, (int)(vars->cub->player->pos_x * 10),
						(int)(vars->cub->player->pos_y * 10),
						0x0000FFFF);
}

void	draw2d(t_vars *vars)
{
	draw_map(vars);
	draw_player(vars);
}
