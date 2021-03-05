/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:03:16 by abirthda          #+#    #+#             */
/*   Updated: 2021/03/04 13:15:58 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "map.h"
# include "mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# define POS_Y vars->cub->player->pos_y
# define POS_X vars->cub->player->pos_x
# define PDIR_X vars->cub->player->dir_x
# define PDIR_Y vars->cub->player->dir_y
# define PLANE_X vars->cub->player->plane_x
# define PLANE_Y vars->cub->player->plane_y
# define MAP vars->cub->map
# define PLAYER vars->cub->player
# define MOVE vars->cub->player->move
# define RAY vars->ray
# define TEXTURE vars->tex
# define SPRITE vars->cub->sprites
# define WIDTH vars->cub->width
# define HEIGHT vars->cub->height
# define ANY_MOVE MOVE->a || MOVE->w || MOVE->s || MOVE->d || MOVE->l || MOVE->r

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_data;

typedef struct		s_texture
{
	void			*mlx;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_texture;

typedef struct		s_tex_tools
{
	unsigned int	color;
	float			step;
	float			pos;
	float			wall_x;
	int				addr_pos;
	int				x;
	int				y;
}					t_tex_tools;

typedef struct		s_sprite_tools
{
	float			x;
	float			y;
	float			inv_det;
	float			transform_y;
	float			transform_x;
	int				screen_x;
	int				height;
	int				width;
	int				start_y;
	int				end_y;
	int				start_x;
	int				end_x;
	int				stripe;
	t_tex_tools		tool;
}					t_sprite_tools;

typedef struct		s_ray
{
	int				r;
	int				side;
	int				step_x;
	int				step_y;
	int				map_x;
	int				map_y;
	float			distance_x;
	float			distance_y;
	float			delta_x;
	float			delta_y;
	float			wall_dist;
	float			dir_x;
	float			dir_y;
	int				wall_height;
	int				wall_start;
	int				wall_end;
}					t_ray;

typedef struct		s_vars
{
	void			*mlx;
	void			*win;
	t_params		*cub;
	t_data			*img;
	t_ray			ray;
	t_texture		**tex;
	int				tex_num;
	float			*z_buffer;
}					t_vars;

void				my_mlx_pixel_put(t_data *data,
									int x,
									int y,
									int color);
void				raycaster(t_vars *vars);
void				texturized_vert_line(t_vars *vars);
void				save_bitmap(t_vars *vars);
void				draw_sprites(t_vars *vars);
void				ft_move(t_vars *vars,
							float move_speed);
void				ft_strafe(t_vars *vars,
							float move_speed);
void				ft_rotate(t_vars *vars,
							float move_speed);
void				vert_line(t_vars *vars,
							int draw_start,
							int draw_end,
							unsigned int color);
void				adjust_screen(t_vars *vars);
void				free_vars(t_vars *vars);
t_vars				*init_main(t_vars *vars, t_params *cub);
int					init_vars(t_vars *vars);
int					ft_close(t_vars *vars);
int					set_texture(t_vars *vars);
int					key_pressed(int	keycode,
								t_vars *vars);
int					key_released(int keycode,
								t_vars *vars);
int					ft_strcmp(const char *s1,
							const char *s2);
int					check_name(char *name);
int					check_args(int argc,
								char **argv,
								int *fd,
								int *save);

#endif
