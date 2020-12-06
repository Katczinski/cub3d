NAME = cub3d

HEADER = ./source/includes

LIBFT = ./libft

SRCS = source/map/parsemap.c\
	   source/map/checks/checks.c\
	   source/map/handlers/handlers.c\
	   source/map/init/ft_init.c\
	   source/tools/tools.c\
	   gnl/get_next_line.c\
	   gnl/get_next_line_utils.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
		@make -C $(LIBFT)
		@echo "Cub3D has been created"

%.o: %.c
		@gcc -I $(HEADER) -c $< -o $@

test: test_clean $(OBJS) 
	  @gcc -I $(HEADER) -c test.c
	  @gcc test.o -L./libft -lft $(OBJS) -o test
	  ./test

test_clean:
		@rm -f $(OBJS)
		@rm -f $(NAME)
		@rm -f test.o
		@rm -f test

clean :
		@make -C $(LIBFT) clean
		@rm -f $(OBJS)
		@echo "Cub3D has been cleaned"

fclean : clean test_clean
		@make -C $(LIBFT) fclean
		@rm -f $(NAME)

re: fclean all
