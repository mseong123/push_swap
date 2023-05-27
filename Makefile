SRCS_NAME = main swap push rotate reverse_rotate ft_atoi_long sort

SRCS = $(SRCS_NAME:=.c)

OBJECTS = $(SRCS:.c=.o)

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -I ./libft $<	

$(NAME): $(OBJECTS)
	make bonus -C ./libft
	cc -fsanitize=address -g $(OBJECTS) -o $(NAME) -L./libft -lft

clean:
	make clean -C ./libft
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
