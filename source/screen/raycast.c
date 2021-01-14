/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 14:59:35 by abirthda          #+#    #+#             */
/*   Updated: 2021/01/14 18:46:57 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#define MAP vars->cub->map
#define PLAYER vars->cub->player
void	vert_line(t_vars *vars, int x, int draw_start, int draw_end, int color)
{
	while (draw_start < draw_end)
		my_mlx_pixel_put(vars->img, x, (draw_start++), color);
}

void	draw_background(t_vars *vars)
{
	for (int w = 0; w < vars->cub->width; w++)
	{
		for (int h = 0; h < vars->cub->height; h++)
		{
			if (h < vars->cub->height/2)
				my_mlx_pixel_put(vars->img, w, h, 0x05FEFF);
			else
				my_mlx_pixel_put(vars->img, w, h, 0x444444);
		}
	}
}
/*
void	castray(t_vars *vars)
{
	const float fov = M_PI/3;
	float 		t = 0;
   	float		c = 0;
	int 		color;
	float 		sideX, sideY;
	float		wall_height;
	for (; t < vars->cub->width; t++) {
		float angle = (float)PLAYER->dir - fov/2 + (fov * t)/(float)vars->cub->width;
		c = 0;
		for (; ; c += 0.1)
		{
			float x = (float)PLAYER->pos_x + c * cos(angle);
			float y = (float)PLAYER->pos_y + c * sin(angle);
	//		if (c > 0)
//			my_mlx_pixel_put(vars->img, (int)(x * 10), (int)(y * 10), 0x00FFFFFF);
			if (MAP[(int)y][(int)x] == '1')
			{
				wall_height = sqrt(x*x + y*y);
				break ;
			}
		}
//		if (x > y)
			color = 0xFF0000;
//		else
//			color = 0xCC0000;
		int	line_height = ((float)vars->cub->height/c);
//		int line_height = 64/c * 15;
//		int line_height = 64/(c * cos(angle - PLAYER->dir));
		int draw_start = vars->cub->height/2 - line_height/2;
		if (draw_start < 0)
			draw_start = 0;
		int	draw_end = draw_start + line_height;
		if (draw_end >= vars->cub->height)
			draw_end = vars->cub->height - 1;
	//	printf("start = %d, end = %d\n", draw_start, draw_end);
		vert_line(vars, (int)t, draw_start, draw_end, color);
	}
}
*/
//--------------------------------------lodev-------------------------------------
/*
void	castray(t_vars *vars)
{
	int x = 0;

//	double fov = PI/3;
	
	for (; x < vars->cub->width; x++)
	{
//		double ra = PLAYER->dir + fov / 2 - fov * x / (double)vars->cub->width;
//		if (ra < 0)
//			ra += 2 * PI;
//		if (ra > 2 * PI)
//			ra -= 2 * PI;
			
		double camera_x = 2 * (double)x /(double)vars->cub->width - 1;
		double raydir_x = vars->cub->player->dir_x + vars->plane_x * camera_x;
		double raydir_y = vars->cub->player->dir_y + vars->plane_y * camera_x;
		int map_x = (int)vars->cub->player->pos_x;
		int map_y = (int)vars->cub->player->pos_y;
		double side_dist_x = 0;
		double side_dist_y = 0;
		double delta_dist_x = (raydir_y == 0) ? 0 : ((raydir_x == 0) ? 1 : fabs(1 / raydir_x));
		double delta_dist_y = (raydir_x == 0) ? 0 : ((raydir_y == 0) ? 1 : fabs(1 / raydir_y));
		double perp_wall_dist = 0;
//		printf("ray[%d]: raydir_x = %f, raydir_y = %f, deltaX = %f, deltaY = %f\n", x, raydir_x, raydir_y, delta_dist_x, delta_dist_y);
		int step_x = 0;
		int step_y = 0;

		int hit = 0;
		int side = 0;
		if (raydir_x < 0)
		{
			step_x = -1;
			side_dist_x = ((vars->cub->player->pos_x - (double)map_x) * delta_dist_x);
		}
		else
		{
			step_x = 1;
			side_dist_x = (((double)map_x + 1.0 - vars->cub->player->pos_x) * delta_dist_x);
		}
		if (raydir_y < 0)
		{
			step_y = -1;
			side_dist_y = ((vars->cub->player->pos_y - (double)map_y) * delta_dist_y);
		}
		else
		{
			step_y = 1;
			side_dist_y = (((double)map_y + 1.0 - vars->cub->player->pos_y) * delta_dist_y);
		}
		printf("ray[%d]: side_dist_x = %f, side_dist_y = %f\n", x, side_dist_x, side_dist_y);
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (vars->cub->map[map_y][map_x] == '1')
				hit = 1;
		}
		
//		perp_wall_dist = cos(fabs(PLAYER->dir - ra));
//		if (side == 0)
//			perp_wall_dist *= side_dist_x;
//		else
//			perp_wall_dist *= side_dist_y;
		
		if (side == 0)
			perp_wall_dist = (((double)map_x - vars->cub->player->pos_x + (double)(1 - step_x) / 2.0) / raydir_x);
		else
			perp_wall_dist = (((double)map_y - vars->cub->player->pos_y + (double)(1 - step_y) / 2.0) / raydir_y);
		int line_height = (int)(vars->cub->height / perp_wall_dist);
//		printf("ray[%d]: line height = %d, perp_wall_dist = %f\n", x, line_height, perp_wall_dist);
		int draw_start = vars->cub->height / 2 - line_height / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + vars->cub->height / 2;
		if (draw_end >= vars->cub->height)
			draw_end = vars->cub->height - 1;
		int color = 0x00FF0000;
		if (side == 1)
			color = color / 2;
		vert_line(vars, x, draw_start, draw_end, color);
	}
//	exit(1);
}
*/

void	castray(t_vars *vars)
{
	int		side;
	int		xStep, yStep;
	double	side_dist_x, side_dist_y;
	double	delta_dist_x, delta_dist_y;
	double	raydir_x, raydir_y;
	int		t = 0;
	double	fov = PI/3;
	double	ra;
	static int		i;
	for (; t < vars->cub->width; t++)
	{
		int 	map_x = (int)PLAYER->pos_x;
		int 	map_y = (int)PLAYER->pos_y;

		ra = PLAYER->dir + fov / 2 - fov * t / (double)vars->cub->width;
		
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
		if (ra < PI)
		{
			yStep = -1;
			side_dist_y = PLAYER->pos_y - map_y;
		}
		else
		{	
			yStep = 1;
			if (ra > PI && ra < 2 * PI)
				side_dist_y = (double)map_y + 1.0 -  PLAYER->pos_y;
			else
				side_dist_y = 0;
		}
		if (ra < 3 * PI / 2 && ra > PI / 2)
		{
			xStep = -1;
			side_dist_x = PLAYER->pos_x - map_x;
		}
		else
		{
			xStep = 1;
			if (ra > 3 * PI / 2 || ra < PI / 2)
				side_dist_x = (double)map_x + 1.0 - PLAYER->pos_x;
			else
				side_dist_x = 0;
		}
//		if (t == 807.0 || t == 808.0)
//			printf("before start: sidedistx = %f, sidedisty = %f\n", side_dist_x, side_dist_y);
		
		side_dist_x = side_dist_x == 0 ? 0 : fabs(side_dist_x / cos(ra));
		side_dist_y = side_dist_y == 0 ? 0 : fabs(side_dist_y / sin(ra));
//		printf("ray[%d]: side_dist_x = %f, side_dist_y = %f\n", t, side_dist_x, side_dist_y);
		delta_dist_y = side_dist_y == 0 ? 0 : side_dist_x == 0 ? 1 : fabs(1 / sin(ra));
		delta_dist_x = side_dist_x == 0 ? 0 : side_dist_y == 0 ? 1 : fabs(1 / cos(ra));
//		printf("ray[%d]: delta_dist_x = %f, delta_dist_y = %f\n", t, delta_dist_x, delta_dist_y);
//		if (t == 807.0 || t == 808.0)
//		{
//			printf("start: sidedistx = %f, sidedisty = %f\n", side_dist_x, side_dist_y);			printf("deltax = %f. deltay = %f\n", delta_dist_x, delta_dist_y);	
//		}
		int hit = 0;
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
//				side_dist_x += delta_dist_x;
				map_x += xStep;
				side = 0;
			}
			else
			{
//				side_dist_y += delta_dist_y;
				map_y += yStep;
				side = 1;
			}
//			if (t == 807.0 || t == 808.0)
//			{
//				printf("mapy = %d, mapx = %d\n", map_y, map_x);
//			}
			if (MAP[map_y][map_x] == '1')
				hit = 1;
			else
			{
				if (side_dist_x < side_dist_y)
					side_dist_x += delta_dist_x;
				else
					side_dist_y += delta_dist_y;
			}
//			if (side_dist_x < side_dist_y)
//				side = 0;
//			else
//				side = 1;
		}
		
//		printf("xStep = %d, yStep = %d\n", xStep, yStep);
//		printf("ray[%d] = %f: sidedistX = %f, sidedistY = %f\ndeltadistX = %f, deltadisty = %f\n\n", i, ra, side_dist_x, side_dist_y, delta_dist_x, delta_dist_y);
		//	printf("ray[%d]: map_y = %d, map_x = %d, side = %d\n\n", i, map_y, map_x, side);
//		i++;
//		if (i == 2)
//			exit(1);
		double	perp_wall_dist = cos(fabs(PLAYER->dir - ra));
		if (side == 0)
			perp_wall_dist *= side_dist_x;
		else
			perp_wall_dist *= side_dist_y;
//		if (t == 807.0 || t == 808.0)
//			printf("end: sidedistx = %f, sidedisty = %f\n", side_dist_x, side_dist_y);
		//	printf("ray[%f]: perp_wall_dist = %f\n", t, perp_wall_dist);
		int line_height = (int)((double)vars->cub->height / perp_wall_dist);
		int draw_start = vars->cub->height / 2 - line_height / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + vars->cub->height / 2;
		if (draw_end >= vars->cub->height)
			draw_end = vars->cub->height - 1;
		int color = 0x00FF00;
		if (side == 1)
			color = color / 2;
		vert_line(vars, t, draw_start, draw_end, color);
	
	}
//	exit(1);
}	

