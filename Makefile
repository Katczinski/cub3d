NAME = cub3d

HEADER = ./source/includes


SRCS = source/map/parsemap.c\
	   source/map/checks/checks.c\
	   source/map/checks/check_map.c\
	   source/map/handlers/handlers.c\
	   source/map/init/ft_init.c\
	   source/map/init/ft_free.c\
	   source/tools/tools.c\
	   source/tools/map_tools.c\
	   source/tools/ft_atoi.c\
	   source/tools/ft_strlen.c\
	   source/tools/get_next_line.c\
	   source/tools/get_next_line_utils.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
		@echo "Cub3D has been created"

%.o: %.c
		@gcc -I $(HEADER) -c $< -o $@

test: re
	  @gcc -I $(HEADER) -c test.c
	  @gcc test.o $(OBJS) -o test
	  ./test

test_clean:
		@rm -f test.o
		@rm -f test

clean :
		@rm -f $(OBJS)
		@echo "Cub3D has been cleaned"

fclean : clean test_clean
		@rm -rf $(NAME)

re: fclean all
