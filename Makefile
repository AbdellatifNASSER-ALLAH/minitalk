
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = utils.c
OBJ =$(SRC:.c=.o) 

SRCS = server.c
OBJS =$(SRCS:.c=.o) 

SRCC = client.c
OBJC =$(SRCC:.c=.o)

SERVER = server 
CLIENT = client

all: $(SERVER) $(CLIENT)
bonus: all
	
$(SERVER): $(OBJS) $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT): $(OBJC) $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
		
clean:
	rm -f $(OBJS) $(OBJC) $(OBJ)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

e:
	vi Makefile

.PHONY: all clean fclean re e
