SOURCES = push_swap.c operations.c operations_1.c outils_tri.c premier_sort.c chaines_utils.c validation.c

OBJS = $(SOURCES:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

all : $(NAME)
$(NAME): 
			$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)
clean: 
					$(RM) $(OBJS)
fclean:		clean
					$(RM) $(NAME)
re:			fclean $(NAME)
