/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:49:46 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/12 16:45:31 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef unsigned int	t_bool;

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
/*
**source/map/checks/check.c
*/
t_bool					ft_is_resolution(char *line);
t_bool					ft_is_texture(char *line);
t_bool					ft_is_sprite(char *line);
t_bool					ft_is_color(char *line);
t_bool					ft_is_empty(char *line);
t_bool					ft_is_map(char *line);
int						ft_check_edge(char *line, int last, char **map);
/*
**source/map/handlers/handlers.c
*/
int						handle_resolution(char *line, t_params *cub);
int						handle_texture(char *line, t_params *cub);
int						handle_sprite(char *line, t_params *cub);
int						handle_color(char *line, t_params *cub);
int						handle_map(int fd, char **line, t_params *cub);
/*
**source/tools/
*/
int						ft_atoi(char *nptr);
int						ft_strlen(char *s);
int						get_next_line(int fd, char **line);
int						check_buff(char *buff);
char					*addtoline(char **line, char *buff);
char					*addtobuff(char *buff, char *tmp);
void					skip_spaces(char **line);
char					*trim_path(char *path);
char					**join_map(char **map, char *line);
char					**align_map(char **map);
int						lines_count(char **map);
/*
**source/map/init/
*/
t_params				*ft_init(t_params *cub);
void					ft_free(t_params *cub);
t_params				*ft_free_gnl(char **line, int fd, t_params *cub);

#endif
