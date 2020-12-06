/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:13:32 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/06 16:23:57 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../../gnl/get_next_line.h"
# include "../../libft/libft.h"
# include <stdio.h>
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

t_params				*parsecub(int fd);
t_bool					ft_is_resolution(char *line);
t_bool					ft_is_texture(char *line);
t_bool					ft_is_sprite(char *line);
t_bool					ft_is_color(char *line);
t_bool					ft_is_map(char *line);
int						handle_resolution(char *line, t_params *cub);
int						handle_texture(char *line, t_params *cub);
char					*trim_path(char *path);
void					ft_init(t_params *cub);

#endif
