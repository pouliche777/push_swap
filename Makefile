S = src/
O = obj/
L = libft/

SOURCES = $Spush_swap.c $Soperations.c $Soperations_1.c $Soutils_tri.c $Ssort.c $Schaines_utils.c $Svalidation.c $Sutils.c $Sutils_1.c

OBJS = $(SOURCES:$S%=$O%.o)

LIB = libft/libft.a
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

all: $(NAME)

$O:
	@mkdir $@

$(OBJS): | $O

$(OBJS): $O%.o: $S%
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(L) --silent
	@$(CC) $(CFLAGS) $(LIB) $^ -o $@
	@echo "\033[0;32m Compilation complétée"

clean: 
		@$(RM) $(OBJS)
		@$(RM) $O
		@make clean -C $(L) --silent
		@echo "\033[0;31m Fichiers .o supprimes"

fclean:	clean
	@$(RM) $(NAME)
	@make fclean -C $(L) --silent
	@echo "\033[0;31m executable supprime"


re:	fclean $(NAME)
	@make re -C $(L) --silent
