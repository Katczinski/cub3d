/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 13:35:23 by abirthda          #+#    #+#             */
/*   Updated: 2021/03/04 12:46:55 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_file_header(int fd, t_vars *vars)
{
	int	file_size;
	int pixel_data_offset;

	file_size = WIDTH * HEIGHT * 4 + 14 + 40 + 4;
	pixel_data_offset = 14 + 40 + 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &pixel_data_offset, 4);
}

void	ft_info_header(int fd, t_vars *vars)
{
	int				n;
	unsigned char	header[28];
	int				header_info_size;
	int				plane_nbr;

	header_info_size = 40;
	plane_nbr = 1;
	n = 0;
	write(fd, &header_info_size, 4);
	write(fd, &vars->cub->width, 4);
	write(fd, &vars->cub->height, 4);
	write(fd, &plane_nbr, 2);
	write(fd, &vars->img->bpp, 2);
	while (n < 28)
		header[n++] = (unsigned char)(0);
	write(fd, &header, 28);
}

void	ft_pixel_data(t_vars *vars, unsigned char *buffer)
{
	int				y;
	int				x;
	int				num;

	y = HEIGHT - 1;
	num = -1;
	while (y >= 0)
	{
		x = -1;
		while (++x < WIDTH)
		{
			buffer[++num] = vars->img->addr[y * vars->img->line_length +
									x * (vars->img->bpp / 8)];
			buffer[++num] = vars->img->addr[y * vars->img->line_length +
									x * (vars->img->bpp / 8) + 1];
			buffer[++num] = vars->img->addr[y * vars->img->line_length +
									x * (vars->img->bpp / 8) + 2];
			buffer[++num] = 0;
		}
		y--;
	}
}

void	save_bitmap(t_vars *vars)
{
	int				fd;
	unsigned char	*buffer;

	if ((buffer = malloc(sizeof(unsigned char) * (WIDTH * HEIGHT * 4))))
	{
		fd = open("cub3D.bmp", O_CREAT | O_WRONLY, S_IRWXU);
		ft_file_header(fd, vars);
		ft_info_header(fd, vars);
		ft_pixel_data(vars, buffer);
		write(fd, buffer, WIDTH * HEIGHT * 4);
		free(buffer);
		close(fd);
	}
	else
		throw_error(0);
	free_vars(vars);
	exit(1);
}
