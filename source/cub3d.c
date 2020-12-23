/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:50:55 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/23 14:40:34 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define POS_Y vars->cub->player->pos_y
#define POS_X vars->cub->player->pos_x
#define MAP vars->cub->map
#define PLAYER vars->cub->player
void	my_mlx_pixel_put(t_data *data,
						int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		key_hook(int keycode, t_vars *vars)
{
	if (keycode == 13)
	{
		POS_Y = MAP[(int)(POS_Y + sin(PLAYER->dir))][(int)POS_X] == '1' ? POS_Y : POS_Y + sin(PLAYER->dir);
		POS_X =  MAP[(int)(POS_Y)][(int)(POS_X + cos(PLAYER->dir))] == '1' ? POS_X : POS_X + cos(PLAYER->dir);
	}
	if (keycode == 0 && MAP[(int)POS_Y][(int)(POS_X - 0.2)] != '1')
		 PLAYER->dir -= 0.2;
	if (keycode == 1)
	{
		POS_Y = MAP[(int)(POS_Y - sin(PLAYER->dir))][(int)POS_X] == '1' ? POS_Y : POS_Y - sin(PLAYER->dir);
		POS_X =  MAP[(int)(POS_Y)][(int)(POS_X - cos(PLAYER->dir))] == '1' ? POS_X : POS_X - cos(PLAYER->dir);
	}
	if (keycode == 2 && MAP[(int)POS_Y][(int)(POS_X + 0.2)] != '1')
		PLAYER->dir += 0.2;
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (1);
}

int		render_next_frame(t_vars *vars)
{
	draw2d(vars);
	castray(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (1);
}

void	start_game(t_params *cub)
{
	t_vars		vars;

	vars.cub = cub;
	vars.img = (t_data*)malloc(sizeof(t_data));
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.cub->width,
										vars.cub->height, "Cub3D");
	vars.img->img = mlx_new_image(vars.mlx, vars.cub->width, vars.cub->height);
	vars.img->addr = mlx_get_data_addr(vars.img->img,
			&vars.img->bits_per_pixel, &vars.img->line_length,
										&vars.img->endian);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_loop(vars.mlx);
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
		start_game(cub);
	else
		return (0);
}
