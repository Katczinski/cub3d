NAME = cub3d

HEADER = ./source/includes

MINILIB = minilib/minilibx_opengl_20191021/

SRCS = source/cub3d.c\
	   source/map/parsemap.c\
	   source/map/checks/checks.c\
	   source/map/checks/check_map.c\
	   source/map/checks/check_cub.c\
	   source/map/handlers/handlers.c\
	   source/map/handlers/handle_error.c\
	   source/map/init/ft_init.c\
	   source/map/init/ft_free.c\
	   source/tools/tools.c\
	   source/tools/map_tools.c\
	   source/tools/ft_atoi.c\
	   source/tools/ft_strlen.c\
	   source/tools/get_next_line.c\
	   source/tools/get_next_line_utils.c\
	   source/tools/ft_putstr_fd.c\
	   source/tools/ft_putchar_fd.c\

FLAGS = -Wall -Wextra -Werror
MLFLAGS = -framework OpenGL -framework AppKit
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
		gcc -o $(NAME) -L $(MINILIB) -lmlx $(MLFLAGS) $(OBJS)
		@echo "Cub3D has been created"

%.o: %.c
		make -C	$(MINILIB)
		@gcc $(FLAGS) -I $(HEADER) -c $< -o $@

test: re
	  	@gcc $(FLAGS) -I $(HEADER) -c test.c
	  	@gcc test.o $(OBJS) -o test
	  	./test

leaks: re
		@gcc $(FLAGS) -I $(HEADER) -c test.c
		@gcc test.o $(OBJS) -o test
		valgrind ./test
norme:
		@norminette $(SRCS) $(HEADER)

test_clean:
		@rm -f test.o
		@rm -f test

clean :
		@make -C $(MINILIB) clean
		@rm -f $(OBJS)
		@echo "Cub3D has been cleaned"

fclean : clean test_clean
		@rm -rf $(NAME)

re: fclean all
