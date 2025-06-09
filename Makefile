NAME = philosofers
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

SRCS =	src/main.c\
		src/utils_libft.c\
		src/utils.c\
		src/init.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re