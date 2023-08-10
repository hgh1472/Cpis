CC = cc 
CFLAGS = -Wall -Werror -Wextra
SRCS = ./d_iv.c ./free.c ./con.c ./h_t.c l_f.c m_ch.c main.c ./li_ut.c
OBJS = $(SRCS:.c=.o)
INC = ./ft_list.h
NAME = rush-02
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I $(INC) $^ -o $@

%.o: %.c $(INC)
	$(CC) $(CFLAGS)  -c $< -o $@ -I $(INC)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
