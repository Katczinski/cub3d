/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 14:59:35 by abirthda          #+#    #+#             */
/*   Updated: 2021/03/04 14:31:56 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_ray(t_vars *vars)
{
	float	camera_x;

	camera_x = (2.0 * (float)RAY.r) / (float)vars->cub->width - 1.0;
	RAY.dir_x = PLAYER->dir_x + PLAYER->plane_x * camera_x;
	RAY.dir_y = PLAYER->dir_y + PLAYER->plane_y * camera_x;
	RAY.map_x = (int)PLAYER->pos_x;
	RAY.map_y = (int)PLAYER->pos_y;
	RAY.distance_x = 0;
	RAY.distance_y = 0;
	if (RAY.dir_y == 0)
		RAY.delta_x = 0;
	else if (RAY.dir_x == 0)
		RAY.delta_x = 1;
	else
		RAY.delta_x = fabs(1 / RAY.dir_x);
	if (RAY.dir_x == 0)
		RAY.delta_y = 0;
	else if (RAY.dir_y == 0)
		RAY.delta_y = 1;
	else
		RAY.delta_y = fabs(1 / RAY.dir_y);
	RAY.wall_dist = 0;
	RAY.step_x = 0;
	RAY.step_y = 0;
	RAY.side = 0;
}

void	calculate_dist(t_vars *vars)
{
	if (RAY.dir_x < 0)
	{
		RAY.step_x = -1;
		RAY.distance_x = ((PLAYER->pos_x - (float)RAY.map_x) * RAY.delta_x);
	}
	else
	{
		RAY.step_x = 1;
		RAY.distance_x = (((float)RAY.map_x + 1.0 -
							PLAYER->pos_x) * RAY.delta_x);
	}
	if (RAY.dir_y < 0)
	{
		RAY.step_y = -1;
		RAY.distance_y = ((PLAYER->pos_y - (float)RAY.map_y) * RAY.delta_y);
	}
	else
	{
		RAY.step_y = 1;
		RAY.distance_y = (((float)RAY.map_y + 1.0 -
							PLAYER->pos_y) * RAY.delta_y);
	}
}

void	cast_ray(t_vars *vars)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (RAY.distance_x < RAY.distance_y)
		{
			RAY.distance_x += RAY.delta_x;
			RAY.map_x += RAY.step_x;
			RAY.side = RAY.step_x > 0 ? 3 : 2;
		}
		else
		{
			RAY.distance_y += RAY.delta_y;
			RAY.map_y += RAY.step_y;
			RAY.side = RAY.step_y > 0 ? 1 : 0;
		}
		if (MAP[RAY.map_y][RAY.map_x] == '1')
			hit = 1;
	}
}

void	draw_wall(t_vars *vars)
{
	if (RAY.side == 3 || RAY.side == 2)
		RAY.wall_dist = (((float)RAY.map_x - PLAYER->pos_x +
							(float)(1 - RAY.step_x) / 2.0) / RAY.dir_x);
	else
		RAY.wall_dist = (((float)RAY.map_y - PLAYER->pos_y +
							(float)(1 - RAY.step_y) / 2.0) / RAY.dir_y);
	vars->z_buffer[RAY.r] = RAY.wall_dist;
	RAY.wall_height = (int)(vars->cub->height / RAY.wall_dist);
	RAY.wall_start = vars->cub->height / 2 - RAY.wall_height / 2;
	if (RAY.wall_start < 0)
		RAY.wall_start = 0;
	RAY.wall_end = RAY.wall_height / 2 + vars->cub->height / 2;
	if (RAY.wall_end >= vars->cub->height)
		RAY.wall_end = vars->cub->height - 1;
	vert_line(vars, 0, RAY.wall_start, vars->cub->ceiling->color);
	texturized_vert_line(vars);
	vert_line(vars, RAY.wall_end, vars->cub->height, vars->cub->floor->color);
}

void	raycaster(t_vars *vars)
{
	RAY.r = 0;
	while (RAY.r < vars->cub->width)
	{
		setup_ray(vars);
		calculate_dist(vars);
		cast_ray(vars);
		draw_wall(vars);
		RAY.r++;
	}
	draw_sprites(vars);
}
