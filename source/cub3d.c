/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:50:55 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/17 18:58:58 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		vars->cub->player->pos_y -= 1;
	if (keycode == 0)
		vars->cub->player->pos_x -= 1;
	if (keycode == 1)
		vars->cub->player->pos_y += 1;
	if (keycode == 2)
		vars->cub->player->pos_x += 1;
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (1);
}

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
	int x,y = 0;

	while (vars->cub->map[y])
	{
		x = 0;
		while (vars->cub->map[y][x])
		{
			if (vars->cub->map[y][x] == '1')
			{
			//	my_mlx_pixel_put(vars->img, x, y, 0x00FF0000);
				draw_square(vars, y, x, 0x00FF0000);
			}
			else
			{
			//	my_mlx_pixel_put(vars->img, x, y, 0x00000000);
				draw_square(vars, y, x, 0x00000000);
			}
			x++;
		}
		y++;
	}
}

void	draw_player(t_vars *vars)
{
	draw_square(vars, vars->cub->player->pos_y,
						vars->cub->player->pos_x,
						0x0000FFFF);
}

int		render_next_frame(t_vars *vars)
{
//	my_mlx_pixel_put(vars->img, vars->cub->player->pos_x, 
//							vars->cub->player->pos_y, 0x00FF0000);
	draw_map(vars);
	draw_player(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	
	return (1);
}

void	start_game(t_params *cub)
{
	t_vars		vars;

	vars.cub = cub;
	vars.img = (t_data*)malloc(sizeof(t_data));
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.cub->width, vars.cub->height, "Cub3D");
	vars.img->img = mlx_new_image(vars.mlx, vars.cub->width, vars.cub->height);
	vars.img->addr = mlx_get_data_addr(vars.img->img,
			&vars.img->bits_per_pixel, &vars.img->line_length, &vars.img->endian);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
//	render_next_frame(&vars);	
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
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
