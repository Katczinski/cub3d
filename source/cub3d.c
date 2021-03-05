/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:50:55 by abirthda          #+#    #+#             */
/*   Updated: 2021/03/04 14:30:19 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data,
						int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int		render_next_frame(t_vars *vars)
{
	float	rot_speed;
	float	move_speed;

	rot_speed = 0.05;
	move_speed = 0.1;
	ft_move(vars, move_speed);
	ft_rotate(vars, rot_speed);
	ft_strafe(vars, move_speed);
	if (MOVE->esc)
		ft_close(vars);
	if (ANY_MOVE)
	{
		raycaster(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	}
	mlx_do_sync(vars->mlx);
	return (1);
}

void	start_game(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, key_pressed, vars);
	mlx_hook(vars->win, 3, 1L << 0, key_released, vars);
	mlx_hook(vars->win, 17, 1L << 0, ft_close, vars);
	mlx_loop_hook(vars->mlx, render_next_frame, vars);
	mlx_loop(vars->mlx);
}

void	setup_vars(t_params *cub, int save)
{
	t_vars		*vars;

	vars = 0;
	vars = init_main(vars, cub);
	if ((init_vars(vars)) <= 0)
	{
		free_vars(vars);
		exit(1);
	}
	vars->img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bpp,
								&vars->img->line_length, &vars->img->endian);
	if (!save)
		vars->win = mlx_new_window(vars->mlx, vars->cub->width,
										vars->cub->height, "Cub3D");
	raycaster(vars);
	if (save)
		save_bitmap(vars);
	else
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
		start_game(vars);
	}
}

int		main(int argc, char **argv)
{
	t_params	*cub;
	int			fd;
	int			save;

	cub = 0;
	save = 0;
	if ((check_args(argc, argv, &fd, &save)) < 0)
		return (-1);
	cub = parsecub(fd);
	if (cub != 0)
		setup_vars(cub, save);
	else
		return (-1);
	return (1);
}
