/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:17:05 by abirthda          #+#    #+#             */
/*   Updated: 2021/02/03 17:22:48 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_bool		check_map(t_params *cub)
{
	if (cub->map == 0)
		return (throw_error(24));
	if (cub->player->pos_x < 0)
		return (throw_error(23));
	return (1);
}

t_bool		check_params(t_params *cub)
{
	if (cub->width < 0)
		return (throw_error(15));
	if (cub->no == 0)
		return (throw_error(16));
	if (cub->ea == 0)
		return (throw_error(17));
	if (cub->we == 0)
		return (throw_error(18));
	if (cub->so == 0)
		return (throw_error(19));
	if (cub->sprite == 0)
		return (throw_error(20));
	if (cub->floor->r < 0)
		return (throw_error(21));
	if (cub->ceiling->r < 0)
		return (throw_error(22));
	return (1);
}

t_bool		check_cub(t_params *cub, int map)
{
	if (map == 0)
		return (check_params(cub));
	else if (map == 1)
		return (check_map(cub));
	return (1);
}
