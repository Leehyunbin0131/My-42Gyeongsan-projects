CC := cc
AR := ar
CFLAGS := -Wall -Wextra -Werror
ARFLAGS := rcs

NAME = libftprintf.a

SRCS := ft_printf.c \
	ft_printf_utils.c \
	formatting.c \
	put_base.c
OBJS := $(SRCS:.c=.o)

all : ${NAME}

${NAME} : ${OBJS}
	${AR} ${ARFLAGS} $@ $^

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re