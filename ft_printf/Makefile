NAME = libftprintf.a
SOURCES = \
	ft_chrprinter.c ft_hexprinter.c ft_intprinter.c ft_printf.c ft_ptrprinter.c \
	ft_strprinter.c ft_unintprinter.c
OBJECTS = $(SOURCES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
all: $(NAME)
$(NAME): $(OBJECTS)
	ar -r $@ $?
%.o: %.c
	$(CC) -c $(CFLAGS) $?
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
