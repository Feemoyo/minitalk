CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

server: server.c utils.c
	$(CC) $(CFLAGS) server.c utils.c -o server

client: client.c utils.c
	$(CC) $(CFLAGS) client.c utils.c -o client

clean:
	rm -rf server client

fclean: clean

re: fclean all

.PHONY: all clean fclean re
