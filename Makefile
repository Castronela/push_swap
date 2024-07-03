SRCS	= main.c algorithm_0.c algorithm_1.c input_processing.c linked_list.c utils.c
OBJS	= $(SRCS:.c=.o)

CC		= gcc -g
CFLAGS	= -Wall -Wextra -Werror #-fsanitize:address
RM		= rm -rf

NAME	= push_swap

all:	$(NAME)		

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all