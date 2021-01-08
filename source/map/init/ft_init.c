/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:51:53 by abirthda          #+#    #+#             */
/*   Updated: 2021/01/04 14:47:58 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int			init_color(t_params *cub)
{
	if (!(cub->floor = (t_color*)malloc(sizeof(t_color))) ||
		!(cub->ceiling = (t_color*)malloc(sizeof(t_color))))
	{
		ft_free(cub);
		return (0);
	}
	cub->floor->r = -1;
	cub->floor->g = -1;
	cub->floor->b = -1;
	cub->ceiling->r = -1;
	cub->ceiling->g = -1;
	cub->ceiling->b = -1;
	return (1);
}

int			init_player(t_params *cub)
{
	if (!(cub->player = (t_player*)malloc(sizeof(t_player))))
	{
		ft_free(cub);
		return (0);
	}
	cub->player->pos_x = -1;
	cub->player->pos_y = -1;
	cub->player->dir = 0;
	cub->player->dir_x = 0;
	cub->player->dir_y = 0;
	return (1);
}

t_params	*ft_init(t_params *cub)
{
	if (!(cub = (t_params*)malloc(sizeof(t_params))))
		return (0);
	cub->height = -1;
	cub->width = -1;
	cub->no = 0;
	cub->so = 0;
	cub->we = 0;
	cub->ea = 0;
	cub->sprite = 0;
	cub->floor = 0;
	cub->ceiling = 0;
	cub->map = 0;
	cub->map_len = 0;
	cub->player = 0;
	if (!(init_color(cub)) || !(init_player(cub)))
	{
		ft_free(cub);
		return (0);
	}
	return (cub);
}
