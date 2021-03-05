/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:40:11 by abirthda          #+#    #+#             */
/*   Updated: 2021/02/04 15:11:03 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_strafe(t_vars *vars, float move_speed)
{
	if (MOVE->d && !MOVE->a)
	{
		POS_Y = MAP[(int)(POS_Y + PLANE_Y * move_speed)][(int)POS_X] == '1' ?
				POS_Y : POS_Y + PLANE_Y * move_speed;
		POS_X = MAP[(int)(POS_Y)][(int)(POS_X + PLANE_X * move_speed)] == '1' ?
				POS_X : POS_X + PLANE_X * move_speed;
	}
	if (MOVE->a && !MOVE->d)
	{
		POS_Y = MAP[(int)(POS_Y - PLANE_Y * move_speed)][(int)(POS_X)] == '1' ?
				POS_Y : POS_Y - PLANE_Y * move_speed;
		POS_X = MAP[(int)(POS_Y)][(int)(POS_X - PLANE_X * move_speed)] == '1' ?
				POS_X : POS_X - PLANE_X * move_speed;
	}
}

void	ft_rotate(t_vars *vars, float rot_speed)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = PDIR_X;
	old_plane_x = PLANE_X;
	if (MOVE->r && !MOVE->l)
	{
		PDIR_X = PDIR_X * cos(rot_speed) - PDIR_Y * sin(rot_speed);
		PDIR_Y = old_dir_x * sin(rot_speed) + PDIR_Y * cos(rot_speed);
		PLANE_X = PLANE_X * cos(rot_speed) - PLANE_Y * sin(rot_speed);
		PLANE_Y = old_plane_x * sin(rot_speed) + PLANE_Y * cos(rot_speed);
	}
	if (MOVE->l && !MOVE->r)
	{
		PDIR_X = PDIR_X * cos(-rot_speed) - PDIR_Y * sin(-rot_speed);
		PDIR_Y = old_dir_x * sin(-rot_speed) + PDIR_Y * cos(-rot_speed);
		PLANE_X = PLANE_X * cos(-rot_speed) - PLANE_Y * sin(-rot_speed);
		PLANE_Y = old_plane_x * sin(-rot_speed) + PLANE_Y * cos(-rot_speed);
	}
}

void	ft_move(t_vars *vars, float move_speed)
{
	if (MOVE->w && !MOVE->s)
	{
		POS_Y = MAP[(int)(POS_Y + PDIR_Y * move_speed)][(int)POS_X] == '1' ?
				POS_Y : POS_Y + PDIR_Y * move_speed;
		POS_X = MAP[(int)(POS_Y)][(int)(POS_X + PDIR_X * move_speed)] == '1' ?
				POS_X : POS_X + PDIR_X * move_speed;
	}
	if (MOVE->s && !MOVE->w)
	{
		POS_Y = MAP[(int)(POS_Y - PDIR_Y * move_speed)][(int)(POS_X)] == '1' ?
				POS_Y : POS_Y - PDIR_Y * move_speed;
		POS_X = MAP[(int)(POS_Y)][(int)(POS_X - PDIR_X * move_speed)] == '1' ?
				POS_X : POS_X - PDIR_X * move_speed;
	}
}
