CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = ./main.c ./ft_putnbr.c ./ft_atoi.c ./operate.c
OBJS = $(SRCS:.c=.o)
NAME = do-op

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@ 

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
