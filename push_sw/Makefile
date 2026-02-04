NAME = push_swap


CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3


SRC = push_swap.c rules.c list_utils.c stack_init.c operations.c rotate.c reverse.c
OBJ = $(SRC:.c=.o)
HEADERS = push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)


re: fclean all


.PHONY: all clean fclean

