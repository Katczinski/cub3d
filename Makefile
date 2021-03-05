NAME = cub3D

HEADER = includes

MINILIB = minilib/

SRCS = source/cub3d.c\
	   source/screen/raycast.c\
	   source/screen/textures/textures.c\
	   source/screen/sprites/sprites.c\
	   source/screen/bitmap/bitmap.c\
	   source/keys/keys.c\
	   source/keys/movement.c\
	   source/map/parsemap.c\
	   source/map/checks/checks.c\
	   source/map/checks/check_map.c\
	   source/map/checks/check_cub.c\
	   source/map/handlers/handlers.c\
	   source/map/handlers/handle_error.c\
	   source/map/init/ft_init.c\
	   source/map/init/ft_free.c\
	   source/tools/ft_init_vars.c\
	   source/tools/path_tools.c\
	   source/tools/map_tools.c\
	   source/tools/screen_tools.c\
	   source/tools/ft_atoi.c\
	   source/tools/ft_strlen.c\
	   source/tools/get_next_line.c\
	   source/tools/get_next_line_utils.c\
	   source/tools/ft_putstr_fd.c\
	   source/tools/ft_putchar_fd.c\
	   source/tools/ft_strcmp.c\

FLAGS = -O3 -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit

MLX = libmlx.dylib

OBJS = $(patsubst %.c,%.o,$(SRCS))

CC = @gcc

all: $(NAME)

$(NAME) : $(OBJS)
		make -C $(MINILIB)
		mv $(MINILIB)/$(MLX) ./
		$(CC) -L. -lmlx $(MLXFLAGS) $(OBJS) -o $(NAME) 

%.o: %.c
		$(CC) $(FLAGS) -I $(HEADER) -I $(MINILIB) -c $< -o $@

norme:
		@norminette $(SRCS) $(HEADER)/*.h

clean : 
		@make -C $(MINILIB) clean
		@rm -f $(OBJS)
		@rm -f $(MLX) 

fclean : clean
		@rm -rf $(NAME) cub3D.bmp

re: fclean all

.PHONY: all clean fclean re
