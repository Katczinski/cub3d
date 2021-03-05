/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:45:30 by abirthda          #+#    #+#             */
/*   Updated: 2021/03/04 12:51:25 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_vars(vars);
	exit(1);
	return (0);
}

int		ft_setmove(int keycode, t_vars *vars, int flag)
{
	MOVE->w = (keycode == 13) ? flag : MOVE->w;
	MOVE->a = (keycode == 0) ? flag : MOVE->a;
	MOVE->s = (keycode == 1) ? flag : MOVE->s;
	MOVE->d = (keycode == 2) ? flag : MOVE->d;
	MOVE->l = (keycode == 123) ? flag : MOVE->l;
	MOVE->r = (keycode == 124) ? flag : MOVE->r;
	MOVE->esc = (keycode == 53) ? flag : MOVE->esc;
	return (1);
}

int		key_pressed(int keycode, t_vars *vars)
{
	ft_setmove(keycode, vars, 1);
	return (1);
}

int		key_released(int keycode, t_vars *vars)
{
	ft_setmove(keycode, vars, 0);
	return (1);
}
