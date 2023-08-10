CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = ./includes/ft.h
NAME = bsq
SRCS = ./srcs/create_tmp.c ./srcs/dp.c ./srcs/fill_square.c \
		./srcs/find_square.c ./srcs/free.c ./srcs/invalid_map.c \
		./srcs/line_check.c ./srcs/main.c ./srcs/process.c
OBJS = $(SRCS:.c=.o)
TEMP = ./tmp.txt

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TEMP) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re