SRCS_NAME = push_swap swap push rotate reverse_rotate ft_atoi_long big_sort small_sort big_sort_utils_1 big_sort_utils_2 big_sort_utils_3 utils_1 utils_2

BONUS_SRCS_NAME = checker swap push rotate reverse_rotate ft_atoi_long big_sort small_sort big_sort_utils_1 big_sort_utils_2 big_sort_utils_3 utils_1 utils_2

SRCS = $(SRCS_NAME:=.c)

BONUS_SRCS = $(BONUS_SRCS_NAME:=.c)

OBJECTS = $(SRCS:.c=.o)

BONUS_OBJECTS = $(BONUS_SRCS:.c=.o)

NAME = push_swap

BONUS_NAME = checker

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -I ./libft $<	

$(NAME): $(OBJECTS)
	make bonus -C ./libft
	cc $(OBJECTS) -o $(NAME) -L./libft -lft

bonus : $(BONUS_OBJECTS) 
	make bonus -C ./libft
	cc $(BONUS_OBJECTS) -o $(BONUS_NAME) -L./libft -lft

clean:
	make clean -C ./libft
	rm -f $(OBJECTS)
	rm -f $(BONUS_OBJECTS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
