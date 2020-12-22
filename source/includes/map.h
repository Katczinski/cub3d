/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:49:46 by abirthda          #+#    #+#             */
/*   Updated: 2020/12/22 16:20:50 by abirthda         ###   ########.fr       */
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

typedef struct			s_player
{
	double				pos_x;
	double				pos_y;
	double				dir;
}						t_player;

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
	t_color				*ceiling;
	t_player			*player;
	char				**map;
	int					map_len;
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
t_bool					check_cub(t_params *cub);
int						ft_check_edge(char *line, int last, char **map);
int						ft_check_map_line(t_params *cub, int y);
/*
**source/map/handlers/handlers.c
*/
int						handle_resolution(char *line, t_params *cub);
int						handle_texture(char *line, t_params *cub);
int						handle_sprite(char *line, t_params *cub);
int						handle_color(char *line, t_params *cub);
int						handle_map(int fd, char **line, t_params *cub);
int						throw_error(int status);
/*
**source/tools/
*/
int						ft_atoi(char *nptr);
int						ft_strlen(char *s);
int						get_next_line(int fd, char **line);
int						check_buff(char *buff);
char					*addtoline(char **line, char *buff);
char					*addtobuff(char *buff, char *tmp);
char					*trim_path(char *path);
char					**join_map(t_params *cub, char *line);
char					**align_map(char **map);
void					skip_spaces(char **line);
void					ft_putstr_fd(char *s, int fd);
void					ft_putchar_fd(char c, int fd);
/*
**source/map/init/
*/
t_params				*ft_init(t_params *cub);
t_params				*ft_free(t_params *cub);
t_params				*ft_free_gnl(char **line, int fd, t_params *cub);

#endif
