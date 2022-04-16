CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

server:
	$(CC) $(CFLAGS) server.c utils.c -o server

client: 
	$(CC) $(CFLAGS) client.c utils.c -o client

clean:
	rm -rf server client

fclean: clean

re: fclean all

.PHONY: all client server fclean clean re
