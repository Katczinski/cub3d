/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:51:53 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/11 16:53:40 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void		ft_free(t_params *cub)
{
	free(cub->floor);
	free(cub->ceilling);
	free(cub->no);
	free(cub->so);
	free(cub->we);
	free(cub->ea);
	free(cub->sprite);
	free(cub);
}

int			init_color(t_params *cub)
{
	if (!(cub->floor = (t_color*)malloc(sizeof(t_color))) ||
		!(cub->ceilling = (t_color*)malloc(sizeof(t_color))))
	{
		ft_free(cub);
		return (0);
	}
	cub->floor->r = -1;
	cub->floor->g = -1;
	cub->floor->b = -1;
	cub->ceilling->r = -1;
	cub->ceilling->g = -1;
	cub->ceilling->b = -1;
	return (1);
}

t_params	*ft_init(t_params *cub)
{
	if (!(cub = (t_params*)malloc(sizeof(t_params))))
		return (0);
	cub->height = 0;
	cub->width = 0;
	cub->no = 0;
	cub->so = 0;
	cub->we = 0;
	cub->ea = 0;
	cub->sprite = 0;
	cub->floor = 0;
	cub->ceilling = 0;
	if (!(init_color(cub)))
	{
		ft_free(cub);
		return (0);
	}
	return (cub);
}
