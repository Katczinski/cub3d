/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <abirthda@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:49:46 by abirthda          #+#    #+#             */
/*   Updated: 2021/02/19 16:35:37 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# define PI 3.1415926535
# define MPLANE_X cub->player->plane_x
# define MPLANE_Y cub->player->plane_y
# define MDIR_X cub->player->dir_x
# define MDIR_Y cub->player->dir_y

typedef unsigned int	t_bool;

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
	unsigned int		color;
}						t_color;

typedef struct			s_move
{
	int					w;
	int					a;
	int					s;
	int					d;
	int					l;
	int					r;
	int					esc;
}						t_move;

typedef struct			s_player
{
	float				pos_x;
	float				pos_y;
	float				dir;
	float				dir_x;
	float				dir_y;
	float				plane_x;
	float				plane_y;
	t_move				*move;
}						t_player;

typedef struct			s_sprites
{
	float				x;
	float				y;
	float				dist;
}						t_sprites;

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
	t_sprites			**sprites;
	char				**map;
	int					sprites_num;
	int					map_len;
	int					map_end;
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
t_bool					check_cub(t_params *cub, int map);
int						ft_check_edge(char *line, int last, t_params *cub);
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
int						ft_is_ws(char c);
char					*addtoline(char **line, char *buff);
char					*addtobuff(char *buff, char *tmp);
char					*trim_path(char *path);
char					**join_map(t_params *cub, char *line);
char					**align_map(char **map);
void					skip_spaces(char **line);
void					ft_putstr_fd(char *s, int fd);
void					ft_putchar_fd(char c, int fd);
t_sprites				**join_sprites(t_params *cub, int y, int x);
/*
**source/map/init/
*/
t_params				*ft_init(t_params *cub);
t_params				*ft_free(t_params *cub);
t_params				*ft_free_gnl(char **line, int fd, t_params *cub);

#endif
