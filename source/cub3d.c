/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:50:55 by abirthda          #+#    #+#             */
/*   Updated: 2021/01/12 18:00:56 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define DIR_X vars->cub->player->dir_x
#define DIR_Y vars->cub->player->dir_y

void	my_mlx_pixel_put(t_data *data,
						int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
//------------------------------------------lodev--------------------------------------
/*
int		key_hook(int keycode, t_vars *vars)
{
	double old_dir_x = PLAYER->dir_x;
	double old_plane_x = vars->plane_x;
	float rot_speed = 0.1;
	if (keycode == 13)
	{
		POS_Y = MAP[(int)(POS_Y + PLAYER->dir_y)][(int)POS_X] == '1' ? POS_Y : POS_Y + PLAYER->dir_y;
		POS_X =  MAP[(int)(POS_Y)][(int)(POS_X + PLAYER->dir_x)] == '1' ? POS_X : POS_X + PLAYER->dir_x;
	}
	if (keycode == 0)
	{
//		PLAYER->dir += 0.1;
//		if (PLAYER->dir > 2 * PI)
//			PLAYER->dir -= 2 * PI;
		PLAYER->dir_x = PLAYER->dir_x * cos(rot_speed) - PLAYER->dir_y * sin(rot_speed);
		PLAYER->dir_y = old_dir_x * sin(rot_speed) + PLAYER->dir_y * cos(rot_speed);
		vars->plane_x = vars->plane_x * cos(rot_speed) - vars->plane_y * sin(rot_speed);
		vars->plane_y = old_plane_x * sin(rot_speed) + vars->plane_y * cos(rot_speed);	
	}
	if (keycode == 1)
	{
		POS_Y = MAP[(int)(POS_Y - PLAYER->dir_y)][(int)POS_X] == '1' ? POS_Y : POS_Y - PLAYER->dir_y;
		POS_X =  MAP[(int)(POS_Y)][(int)(POS_X - PLAYER->dir_x)] == '1' ? POS_X : POS_X - PLAYER->dir_x;
	}
	if (keycode == 2)
	{
//		PLAYER->dir -= 0.1;
//		if (PLAYER->dir < 0)
//			PLAYER->dir += 2 * PI;
		PLAYER->dir_x = PLAYER->dir_x * cos(-rot_speed) - PLAYER->dir_y * sin(-rot_speed);
		PLAYER->dir_y = old_dir_x * sin(-rot_speed) + PLAYER->dir_y * cos(-rot_speed);
		vars->plane_x = vars->plane_x * cos(-rot_speed) - vars->plane_y * sin(-rot_speed);
		vars->plane_y = old_plane_x * sin(-rot_speed) + vars->plane_y * cos(-rot_speed);	
	
	}
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
//	printf("plane_x = %f, plane_y = %f\n", vars->plane_x, vars->plane_y);
	return (1);
}

*/
int		key_hook(int keycode, t_vars *vars)
{
	DIR_Y = sin(PLAYER->dir);
	DIR_X = cos(PLAYER->dir);
	if (keycode == 13)
	{
		POS_Y = MAP[(int)(POS_Y - DIR_Y)][(int)POS_X] == '1' ? POS_Y : POS_Y - DIR_Y;
		POS_X =  MAP[(int)(POS_Y)][(int)(POS_X + DIR_X)] == '1' ? POS_X : POS_X + DIR_X;
	}
	if (keycode == 0)
	{
		PLAYER->dir += 0.1;
		if (PLAYER->dir > 2 * PI)
			PLAYER->dir -= 2 * PI;
	}
	if (keycode == 1)
	{
		POS_Y = MAP[(int)(POS_Y + DIR_Y)][(int)POS_X] == '1' ? POS_Y : POS_Y + DIR_Y;
		POS_X =  MAP[(int)(POS_Y)][(int)(POS_X - DIR_X)] == '1' ? POS_X : POS_X - DIR_X;
	}
	if (keycode == 2)
	{
		PLAYER->dir -= 0.1;
		if (PLAYER->dir < 0)
			PLAYER->dir += 2 * PI;
	}
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (1);
}

int		render_next_frame(t_vars *vars)
{
//	draw2d(vars);
//	draw_player(vars);	
	draw_background(vars);
	castray(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (1);
}

void	start_game(t_vars *vars)
{
	mlx_loop_hook(vars->mlx, render_next_frame, vars);
	mlx_hook(vars->win, 2, 1L << 0, key_hook, vars);
	mlx_loop(vars->mlx);

}

void	init_vars(t_params *cub)
{
	t_vars		vars;
	
	vars.cub = cub;
	vars.img = (t_data*)malloc(sizeof(t_data));
	
	vars.cub->player->dir_x = 0;
	vars.cub->player->dir_y = 1;
	vars.plane_x = 0.66;
	vars.plane_y = 0;	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.cub->width,
										vars.cub->height, "Cub3D");
	vars.img->img = mlx_new_image(vars.mlx, vars.cub->width, vars.cub->height);
	vars.img->addr = mlx_get_data_addr(vars.img->img,
			&vars.img->bits_per_pixel, &vars.img->line_length,
										&vars.img->endian);
	start_game(&vars);
}

int		main(int argc, char **argv)
{
	t_params	*cub;
	int			fd;

	cub = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (0);
	cub = parsecub(fd);
	if (cub != 0)
		init_vars(cub);
	else
		return (0);
}
