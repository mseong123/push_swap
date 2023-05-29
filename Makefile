SRCS_NAME = main swap push rotate reverse_rotate ft_atoi_long big_sort small_sort big_sort_utils_1 big_sort_utils_2 big_sort_utils_3 main_utils

SRCS = $(SRCS_NAME:=.c)

OBJECTS = $(SRCS:.c=.o)

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -I ./libft $<	

$(NAME): $(OBJECTS)
	make bonus -C ./libft
	cc -fsanitize=address $(OBJECTS) -o $(NAME) -L./libft -lft

clean:
	make clean -C ./libft
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
