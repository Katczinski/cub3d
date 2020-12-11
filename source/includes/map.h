/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:13:32 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/08 16:24:13 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

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
int						handle_map(int fd, char **line, t_params *cub);
int						ft_atoi(char *nptr);
int						ft_strlen(char *s);
char					*trim_path(char *path);
char					**join_map(char **map, char *line);
t_params				*ft_init(t_params *cub);
void					ft_free(t_params *cub);
void					skip_spaces(char **line);
#endif
