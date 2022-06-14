SOURCES = push_swap.c

OBJS = $(SOURCES:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = libpush_swap.a

$(NAME):	$(OBJS)
					ar rcs $(NAME) $(OBJS)

all : $(NAME)
compile: 
			$(CC) $(CFLAGS) $(SOURCES)
clean: 
					$(RM) $(OBJS)
fclean:		clean
					$(RM) $(NAME)
re:			fclean $(NAME)
