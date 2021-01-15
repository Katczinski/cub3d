/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 14:59:35 by abirthda          #+#    #+#             */
/*   Updated: 2021/01/15 18:23:00 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vert_line(t_vars *vars, int x, int draw_start, int draw_end, int color)
{
	while (draw_start < draw_end)
		my_mlx_pixel_put(vars->img, x, (draw_start++), color);
}

void	draw_background(t_vars *vars)
{
	int	w;
	int	h;

	w = 0;

	while (w < vars->cub->width)
	{
		h = 0;
		while (h < vars->cub->height)
		{
			if (h < vars->cub->height/2)
				my_mlx_pixel_put(vars->img, w, h, 0x8CD3FF);
			else
				my_mlx_pixel_put(vars->img, w, h, 0x444444);
			h++;
		}
		w++;
	}
}

void	castray(t_vars *vars)
{

	int hit;
	double	fov = PI/3;
	RAY = (t_ray*)malloc(sizeof(t_ray));
	RAY->r = 0;
	while (RAY->r < vars->cub->width)
	{
		RAY->map_x = (int)PLAYER->pos_x;
		RAY->map_y = (int)PLAYER->pos_y;
		RAY->angle = PLAYER->dir + fov / 2 - fov * RAY->r / (double)vars->cub->width;
		RAY->distance_x = 1;
		RAY->distance_y = 1;
		if (RAY->angle < 0)
			RAY->angle += 2 * PI;
		if (RAY->angle > 2 * PI)
			RAY->angle -= 2 * PI;
		if (RAY->angle < PI)
		{
			RAY->step_y = -1;
			RAY->distance_y = PLAYER->pos_y - RAY->map_y;
		}
		else
		{	
			RAY->step_y = 1;
			if (RAY->angle > PI && RAY->angle < 2 * PI)
				RAY->distance_y = (double)RAY->map_y + 1.0 -  PLAYER->pos_y;
		}
		if (RAY->angle < 3 * PI / 2 && RAY->angle > PI / 2)
		{
			RAY->step_x = -1;
			RAY->distance_x = PLAYER->pos_x - RAY->map_x;
		}
		else
		{
			RAY->step_x = 1;
			if (RAY->angle > 3 * PI / 2 || RAY->angle < PI / 2)
				RAY->distance_x = (double)RAY->map_x + 1.0 - PLAYER->pos_x;
		}
		RAY->delta_y = fabs(1 / sin(RAY->angle));
		RAY->delta_x = fabs(1 / cos(RAY->angle));
	
		RAY->distance_x = fabs(RAY->distance_x  / cos(RAY->angle));
		RAY->distance_y = fabs(RAY->distance_y  / sin(RAY->angle));
			hit = 0;		
		while (hit == 0)
		{
			if (RAY->distance_x < RAY->distance_y)
			{
				RAY->map_x += RAY->step_x;
				RAY->side = 0;
			}
			else
			{
				RAY->map_y += RAY->step_y;
				RAY->side = 1;
			}
			if (MAP[RAY->map_y][RAY->map_x] == '1')
				hit = 1;
			else
			{
				if (RAY->distance_x < RAY->distance_y)
					RAY->distance_x += RAY->delta_x;
				else
					RAY->distance_y += RAY->delta_y;
			}
		}
		RAY->wall_dist = cos(fabs(RAY->angle - PLAYER->dir));
		if (RAY->side == 0)
			RAY->wall_dist *= RAY->distance_x;
		else
			RAY->wall_dist *= RAY->distance_y;
		RAY->wall_height = (int)(vars->cub->height / (RAY->wall_dist));
		RAY->wall_start = vars->cub->height / 2 - RAY->wall_height / 2;
		if (RAY->wall_start < 0)
			RAY->wall_start = 0;
		RAY->wall_end = vars->cub->height / 2 + RAY->wall_height / 2;
		if (RAY->wall_end >= vars->cub->height)
			RAY->wall_end = vars->cub->height - 1;
		printf("ray[%d]: wall_height = %d, actual_wall_height = %d | ra - dir = %f\n", RAY->r, RAY->wall_height, RAY->wall_end - RAY->wall_start, fabs(RAY->angle - PLAYER->dir));
		int color = 0x808080;
		if (RAY->side == 1)
			color = 0xA9A9A9;
		vert_line(vars, RAY->r, 0, RAY->wall_start, 0x8CD3FF);
		vert_line(vars, RAY->r, RAY->wall_end, vars->cub->height, 0x444444); 
		vert_line(vars, RAY->r, RAY->wall_start, RAY->wall_end, color);
		RAY->r++;
	}
//	printf("-----------------------------------------------------------\n");
//	exit(1);
}
