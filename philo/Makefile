CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LFLAGS	= -lpthread #-fsanitize=thread -fPIE -g
NAME	= philo
SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME) $(ARGS)

.PHONY: all clean fclean re run