CC=cc
CFLAGS = -Wall -Wextra -Werror
TARGET=bsq
SRCDIR=src
HEADER=include
SRC=$(wildcard $(SRCDIR)/*.c)
OBJS=$(SRC:.c=.o)

all : $(TARGET)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(SRCDIR)/*.o

fclean: clean
	rm -f $(TARGET)

re: fclean all
