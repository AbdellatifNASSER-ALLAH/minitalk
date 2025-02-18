
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = server.c
OBJS =$(SRCS:.c=.o) 

SRCC = client.c
OBJC =$(SRCC:.c=.o)

SERVER = server 
CLIENT = client

all: $(SERVER) $(CLIENT)
	
$(SERVER): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT): $(OBJC)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
		
clean:
	rm -f $(OBJS) $(OBJC)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
