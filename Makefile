NAME = philosofers
CC = cc
CFLAGS = -Wall -Werror -Wextra -g 

SRCS =	src/main.c\
		src/checker_rutine.c\
		src/eat_philo_rutine.c\
		src/init_2.c\
		src/init.c\
		src/parse.c\
		src/philos_rutines.c\
		src/rutines.c\
		src/utils_libft.c\
		src/utils.c\
		src/utils_free.c\

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