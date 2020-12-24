/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 14:59:35 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/24 17:05:20 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
/*
void	castray(t_vars *vars)
{
	double plane_x = 0, plane_y = 0.66;

	for (int x = 0; x < vars->cub->width; x++)
	{
		double camera_x = ((2 * (double)x /(double)vars->cub->width) - 1);
		double raydir_x = vars->cub->player->dir_x + plane_x * camera_x;
		double raydir_y = vars->cub->player->dir_y + plane_y * camera_x;
		int map_x = (int)vars->cub->player->pos_x;
		int map_y = (int)vars->cub->player->pos_y;
		double side_dist_x = 0;
		double side_dist_y = 0;
		double delta_dist_x = (raydir_y == 0) ? 0 : ((raydir_x == 0) ? 1 :fabs(1 / raydir_x));
		double delta_dist_y = (raydir_x == 0) ? 0 : ((raydir_y == 0) ? 1 :fabs(1 / raydir_y));
		double perp_wall_dist = 0;
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
			side_dist_x = ((double)(map_x + 1 - (int)vars->cub->player->pos_x) * delta_dist_x);
		}
		if (raydir_y < 0)
		{
			step_y = -1;
			side_dist_x = ((vars->cub->player->pos_y - (double)map_y) * delta_dist_y);
		}
		else
		{
			step_y = 1;
			side_dist_y = ((double)(map_y + 1 - (int)vars->cub->player->pos_y) * delta_dist_y);
		}
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
		if (side == 0)
			perp_wall_dist = (((double)map_x - vars->cub->player->pos_x + (1 - step_x) / 2) / raydir_x);
		else
			perp_wall_dist = (((double)map_y - vars->cub->player->pos_y + (1 - step_y) / 2) / raydir_y);
		int line_height = (perp_wall_dist == 0) ? vars->cub->height - 1 :(int)((double)vars->cub->height / perp_wall_dist);
		int draw_start = -line_height / 2 + vars->cub->height / 2;
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
}
*/
