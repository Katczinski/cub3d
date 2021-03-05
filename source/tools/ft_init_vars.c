/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:23:33 by abirthda          #+#    #+#             */
/*   Updated: 2021/03/04 13:57:22 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_vars(t_vars *vars)
{
	int	i;

	i = 0;
	if (TEXTURE)
	{
		while (i < vars->tex_num)
		{
			free(TEXTURE[i]);
			TEXTURE[i] = 0;
			i++;
		}
	}
	ft_free(vars->cub);
	free(TEXTURE);
	free(vars->z_buffer);
	free(vars->img);
	free(vars);
}

t_vars	*init_main(t_vars *vars, t_params *cub)
{
	if (!(vars = (t_vars*)malloc(sizeof(t_vars))))
	{
		ft_free(cub);
		throw_error(0);
		exit(1);
	}
	vars->img = 0;
	vars->tex = 0;
	vars->z_buffer = 0;
	vars->tex_num = 0;
	vars->cub = cub;
	return (vars);
}

int		init_vars(t_vars *vars)
{
	int i;

	i = 0;
	if (!(vars->mlx = mlx_init()))
		return (throw_error(28));
	adjust_screen(vars);
	if (!(vars->img = (t_data*)malloc(sizeof(t_data))) ||
		!(vars->tex = (t_texture**)malloc(sizeof(t_texture*) * 6)))
		return (throw_error(0));
	while (i < 6)
		TEXTURE[i++] = 0;
	if (!(vars->z_buffer = (float*)malloc(sizeof(float) * (WIDTH + 1))))
		return (throw_error(0));
	vars->cub->floor->color = (vars->cub->floor->r << 16) +
								(vars->cub->floor->g << 8) +
								(vars->cub->floor->b);
	vars->cub->ceiling->color = (vars->cub->ceiling->r << 16) +
								(vars->cub->ceiling->g << 8) +
								(vars->cub->ceiling->b);
	if (!(set_texture(vars)))
		return (throw_error(0));
	return (1);
}
