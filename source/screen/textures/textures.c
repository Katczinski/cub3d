/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:29:37 by abirthda          #+#    #+#             */
/*   Updated: 2021/03/04 13:59:39 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texturized_vert_line(t_vars *vars)
{
	t_tex_tools	tex;

	if (RAY.side == 0 || RAY.side == 1)
		tex.wall_x = PLAYER->pos_x + RAY.wall_dist * RAY.dir_x;
	else
		tex.wall_x = PLAYER->pos_y + RAY.wall_dist * RAY.dir_y;
	tex.wall_x = (RAY.side == 0 || RAY.side == 3) ?
		1 - (tex.wall_x - floor(tex.wall_x)) : tex.wall_x - floor(tex.wall_x);
	tex.x = (int)(tex.wall_x * (double)TEXTURE[RAY.side]->width);
	tex.x = TEXTURE[RAY.side]->width - tex.x - 1;
	tex.step = 1.0 * TEXTURE[RAY.side]->height / RAY.wall_height;
	tex.pos = (RAY.wall_start - vars->cub->height / 2 +
				RAY.wall_height / 2) * tex.step;
	while (RAY.wall_start < RAY.wall_end)
	{
		tex.y = (int)tex.pos < 0 ? 0 : (int)tex.pos;
		tex.y = tex.y > TEXTURE[RAY.side]->width ?
				TEXTURE[RAY.side]->width - 1 : tex.y;
		tex.pos += tex.step;
		tex.addr_pos = (tex.y * TEXTURE[RAY.side]->line_length + tex.x *
							(TEXTURE[RAY.side]->bits_per_pixel / 8));
		tex.color = *(unsigned int*)(TEXTURE[RAY.side]->addr + tex.addr_pos);
		my_mlx_pixel_put(vars->img, RAY.r, RAY.wall_start, tex.color);
		RAY.wall_start++;
	}
}

void	get_image(t_vars *vars)
{
	TEXTURE[0]->img = mlx_xpm_file_to_image(vars->mlx,
											vars->cub->no,
											&TEXTURE[0]->width,
											&TEXTURE[0]->height);
	TEXTURE[1]->img = mlx_xpm_file_to_image(vars->mlx,
											vars->cub->so,
											&TEXTURE[1]->width,
											&TEXTURE[1]->height);
	TEXTURE[2]->img = mlx_xpm_file_to_image(vars->mlx,
											vars->cub->we,
											&TEXTURE[2]->width,
											&TEXTURE[2]->height);
	TEXTURE[3]->img = mlx_xpm_file_to_image(vars->mlx,
											vars->cub->ea,
											&TEXTURE[3]->width,
											&TEXTURE[3]->height);
	TEXTURE[4]->img = mlx_xpm_file_to_image(vars->mlx,
											vars->cub->sprite,
											&TEXTURE[4]->width,
											&TEXTURE[4]->height);
}

void	get_data_addr(t_vars *vars)
{
	TEXTURE[0]->addr = mlx_get_data_addr(TEXTURE[0]->img,
										&TEXTURE[0]->bits_per_pixel,
										&TEXTURE[0]->line_length,
										&TEXTURE[0]->endian);
	TEXTURE[1]->addr = mlx_get_data_addr(TEXTURE[1]->img,
										&TEXTURE[1]->bits_per_pixel,
										&TEXTURE[1]->line_length,
										&TEXTURE[1]->endian);
	TEXTURE[2]->addr = mlx_get_data_addr(TEXTURE[2]->img,
										&TEXTURE[2]->bits_per_pixel,
										&TEXTURE[2]->line_length,
										&TEXTURE[2]->endian);
	TEXTURE[3]->addr = mlx_get_data_addr(TEXTURE[3]->img,
										&TEXTURE[3]->bits_per_pixel,
										&TEXTURE[3]->line_length,
										&TEXTURE[3]->endian);
	TEXTURE[4]->addr = mlx_get_data_addr(TEXTURE[4]->img,
										&TEXTURE[4]->bits_per_pixel,
										&TEXTURE[4]->line_length,
										&TEXTURE[4]->endian);
}

int		set_texture(t_vars *vars)
{
	while (vars->tex_num < 5)
	{
		if (!(TEXTURE[vars->tex_num] = (t_texture*)malloc(sizeof(t_texture))))
			return (0);
		vars->tex_num++;
	}
	get_image(vars);
	get_data_addr(vars);
	return (1);
}
