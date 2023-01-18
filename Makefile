NAME = minitalk
PRNTF_LIB = ./ft_printf/libftprintf.a
SRC_SRVR = server.c
SRC_CLNT = client.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ_SRVR = $(SRC_SRVR:.c=.o)
OBJ_CLNT = $(SRC_CLNT:.c=.o)

$(PRNTF_LIB):
	make -C ./ft_printf

$(NAME): $(OBJ_SRVR) $(OBJ_CLNT)
	$(CC) $(CFLAGS) $(OBJ_SRVR) -o server $(PRNTF_LIB)
	$(CC) $(CFLAGS) $(OBJ_CLNT) -o client $(PRNTF_LIB)

all: $(PRNTF_LIB) $(NAME)

bonus:	server_bonus.c client_bonus.c
	make -C ./ft_printf
	$(CC) $(CFLAGS) server_bonus.c -o server $(PRNTF_LIB)
	$(CC) $(CFLAGS) client_bonus.c -o client $(PRNTF_LIB)

clean:
	rm -rf $(OBJ_SRVR) $(OBJ_CLNT)
	rm -rf server_bonus.o client_bonus.o

fclean: clean
	rm -rf server client

ffclean: fclean
	make fclean -C ./ft_printf

re: fclean all

.PHONY: all clean fclean ffclean re bonus