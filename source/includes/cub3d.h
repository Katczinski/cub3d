/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:03:16 by abirthda          #+#    #+#             */
/*   Updated: 2021/01/15 17:41:27 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "map.h"
# include "mlx.h"
# define PI 3.1415926535
# define DEG 0.0174533
# define POS_Y vars->cub->player->pos_y
# define POS_X vars->cub->player->pos_x
# define MAP vars->cub->map
# define PLAYER vars->cub->player
# define RAY vars->ray
typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_ray
{
	int			side;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	int			r;
	float		distance_x;
	float		distance_y;
	float		delta_x;
	float		delta_y;
	float		wall_dist;
	int			wall_height;
	int			wall_start;
	int			wall_end;
	float		angle;
}				t_ray;

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	double		plane_x;
	double		plane_y;
	t_params	*cub;
	t_data		*img;
	t_ray		*ray;
}				t_vars;

void			draw2d(t_vars *vars);
void			draw_square(t_vars *vars, int x, int y, int color);
void			draw_background(t_vars *vars);
void			draw_map(t_vars *vars);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			castray(t_vars *vars);
#endif
