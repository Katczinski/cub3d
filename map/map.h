/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:13:32 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/04 15:05:07 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "gnl/get_next_line.h"

typedef unsigned int 	t_bool;
typedef struct			s_params
{
	int					width;
	int					height;
	char				*so;
	char				*we;
	char				*ea;
	char				*no;
	char				*sprite;
	char				*floor; // maybe it's better to use another struct with RGB ints
	char				*ceilling; // same
	char				**map;
}						t_params;

t_bool					ft_is_resolution(char *line);
t_bool					ft_is_texture(char *line);
t_bool					ft_is_sprite(char *line);
t_bool					ft_is_floor(char *line);
t_bool					ft_is_ceilling(char *line);
t_bool					ft_is_map(char *line);

#endif
