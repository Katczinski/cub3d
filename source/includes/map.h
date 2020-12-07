/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:13:32 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/07 14:39:20 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../../gnl/get_next_line.h"
# include "../../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef unsigned int 	t_bool;

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct			s_params
{
	int					width;
	int					height;
	char				*so;
	char				*we;
	char				*ea;
	char				*no;
	char				*sprite;
	t_color				*floor;
	t_color				*ceilling;
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
int						handle_sprite(char *line, t_params *cub);
int						handle_color(char *line, t_params *cub);
char					*trim_path(char *path);
t_params				*ft_init(t_params *cub);
void					ft_free(t_params *cub);

#endif
