/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:40:00 by abirthda          #+#    #+#             */
/*   Updated: 2021/03/04 12:50:24 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vert_line(t_vars *vars,
					int draw_start,
					int draw_end,
					unsigned int color)
{
	while (draw_start < draw_end)
		my_mlx_pixel_put(vars->img, RAY.r, (draw_start++), color);
}

void	adjust_screen(t_vars *vars)
{
	int	size_x;
	int	size_y;

	mlx_get_screen_size(vars->mlx, &size_x, &size_y);
	if (WIDTH > size_x)
		WIDTH = size_x;
	if (HEIGHT > size_y)
		HEIGHT = size_y;
}
