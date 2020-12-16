/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:50:55 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/16 17:11:50 by abirthda         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_params	*cub;
	int			fd;
	void		*mlx;
	void		*mlx_win;
	t_data		img;

	cub = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (0);
	cub = parsecub(fd);
	if (cub != 0)
	{
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, cub->width, cub->height, "Cub3D");
		img.img = mlx_new_image(mlx, cub->width, cub->height);
		img.addr = mlx_get_data_addr(img.img,
				&img.bits_per_pixel, &img.line_length, &img.endian);
		my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
	}
}
