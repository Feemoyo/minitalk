CC = gcc
CFLAGS = -Wall -Wextra -Werror

U_NAME = utils.c

OBJ = $(U_NAME:.c=.o)
SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT)

$(SERVER):$(OBJ) minitalk.h
	$(CC) $(CFLAGS) $(SERVER).c $(OBJ) -o $(SERVER)

$(CLIENT):$(OBJ) minitalk.h
	$(CC) $(CFLAGS) $(CLIENT).c $(OBJ) -o $(CLIENT)

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re SERVER CLIENT