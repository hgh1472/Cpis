CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
INC = ./includes/ft.h
NAME = libft.a
all : $(NAME)

$(NAME) : $(OBJS)
	ar -crs $@ $<

$(OBJS) : $(SRCS) $(INC)
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean : 
	rm -f $(NAME)

fclean : clean
	rm -f $(OBJS)

re : fclean all

.PHONY : all clean fclean re
