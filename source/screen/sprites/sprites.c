/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:08:41 by abirthda          #+#    #+#             */
/*   Updated: 2021/03/04 12:30:32 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_swap(t_sprites *s1, t_sprites *s2)
{
	float swap;

	swap = s1->x;
	s1->x = s2->x;
	s2->x = swap;
	swap = s1->y;
	s1->y = s2->y;
	s2->y = swap;
	swap = s1->dist;
	s1->dist = s2->dist;
	s2->dist = swap;
}

void	sort_sprites(t_vars *vars)
{
	int	i;
	int j;

	i = 0;
	while (i < vars->cub->sprites_num)
	{
		SPRITE[i]->dist = (PLAYER->pos_x - SPRITE[i]->x) *
							(PLAYER->pos_x - SPRITE[i]->x) +
							(PLAYER->pos_y - SPRITE[i]->y) *
							(PLAYER->pos_y - SPRITE[i]->y);
		i++;
	}
	i = 0;
	while (i < vars->cub->sprites_num - 1)
	{
		j = 0;
		while (j < vars->cub->sprites_num - i - 1)
		{
			if (SPRITE[j]->dist < SPRITE[j + 1]->dist)
				ft_swap(SPRITE[j], SPRITE[j + 1]);
			j++;
		}
		i++;
	}
}

void	setup_sprite(t_vars *vars, t_sprite_tools *sprite, int i)
{
	sprite->x = SPRITE[i]->x - PLAYER->pos_x;
	sprite->y = SPRITE[i]->y - PLAYER->pos_y;
	sprite->inv_det = 1.0 / (PLAYER->plane_x * PLAYER->dir_y -
							PLAYER->dir_x * PLAYER->plane_y);
	sprite->transform_x = sprite->inv_det * (PLAYER->dir_y * sprite->x -
											PLAYER->dir_x * sprite->y);
	sprite->transform_y = sprite->inv_det * (-PLAYER->plane_y * sprite->x +
											PLAYER->plane_x * sprite->y);
	sprite->screen_x = (int)((vars->cub->width / 2) *
						(1 + sprite->transform_x / sprite->transform_y));
	sprite->height = abs((int)(vars->cub->height / sprite->transform_y));
	sprite->start_y = -sprite->height / 2 + vars->cub->height / 2;
	if (sprite->start_y < 0)
		sprite->start_y = 0;
	sprite->end_y = sprite->height / 2 + vars->cub->height / 2;
	if (sprite->end_y > vars->cub->height)
		sprite->end_y = vars->cub->height;
	sprite->width = abs((int)(vars->cub->height / sprite->transform_y));
	sprite->start_x = -sprite->width / 2 + sprite->screen_x;
	if (sprite->start_x < 0)
		sprite->start_x = 0;
	sprite->end_x = sprite->width / 2 + sprite->screen_x;
	if (sprite->end_x > vars->cub->width)
		sprite->end_x = vars->cub->width;
	sprite->stripe = sprite->start_x;
}

void	sprite_vert_line(t_vars *vars, t_sprite_tools *sprite)
{
	int	y;
	int d;

	y = sprite->start_y;
	while (y < sprite->end_y)
	{
		d = y * 256 - vars->cub->height * 128 + sprite->height * 128;
		sprite->tool.y = ((d * TEXTURE[4]->height) / sprite->height) / 256;
		sprite->tool.addr_pos = (sprite->tool.y * TEXTURE[4]->line_length +
								sprite->tool.x *
								(TEXTURE[4]->bits_per_pixel / 8));
		sprite->tool.color = *(unsigned int*)(TEXTURE[4]->addr +
									sprite->tool.addr_pos);
		if ((sprite->tool.color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(vars->img, sprite->stripe, y,
							sprite->tool.color);
		y++;
	}
}

void	draw_sprites(t_vars *vars)
{
	int				i;
	t_sprite_tools	sprite;

	i = 0;
	sort_sprites(vars);
	while (i < vars->cub->sprites_num)
	{
		setup_sprite(vars, &sprite, i);
		while (sprite.stripe < sprite.end_x)
		{
			sprite.tool.x = (int)(256 * (sprite.stripe -
						(-sprite.width / 2 + sprite.screen_x)) *
						TEXTURE[4]->width / sprite.width) / 256;
			if (sprite.transform_y > 0 && sprite.stripe > 0 &&
				sprite.stripe < vars->cub->width &&
				sprite.transform_y < vars->z_buffer[sprite.stripe])
				sprite_vert_line(vars, &sprite);
			sprite.stripe++;
		}
		i++;
	}
}
