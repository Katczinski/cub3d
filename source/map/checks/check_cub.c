/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:17:05 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/14 17:45:38 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_bool		check_cub(t_params *cub)
{
	if (cub->width < 0)
		return (throw_error(15));
	else if (cub->no == 0)
		return (throw_error(16));
	else if (cub->ea == 0)
		return (throw_error(17));
	else if (cub->we == 0)
		return (throw_error(18));
	else if (cub->so == 0)
		return (throw_error(19));
	else if (cub->sprite == 0)
		return (throw_error(20));
	else if (cub->floor->r < 0)
		return (throw_error(21));
	else if (cub->ceiling->r < 0)
		return (throw_error(22));
	else if (cub->player->pos_x < 0)
		return (throw_error(23));
	else if (cub->map == 0)
		return (throw_error(24));
	else
		return (1);
}
//DOESN'T WORK YET
