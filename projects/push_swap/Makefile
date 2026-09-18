NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
	arg_parse.c \
	instructions.c \
	operations_reverse_rotate.c \
	operations_rotate.c \
	operations_swap_push.c \
	parse_nbr.c \
	sort_simple.c \
	stack_alloc.c \
	stack_init.c \
	stack_utils.c \
	ft_printf.c \
	ft_printf_utils.c \
	formatting.c \
	bench.c \
	libft_utils.c \
	ft_split.c \
	sort_medium.c \
	sort_complex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
