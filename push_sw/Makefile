NAME = push_swap


CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 -I./includes
LIB_A = ./libft/libft.a
LIB_DIR = ./libft
SRC = main.c push_swap.c rules.c list_utils.c stack_init.c operations.c rotate.c reverse.c input_validation.c input_validation_command.c input_convertion.c manager_input.c insertion_sort.c ./libft/libft.a 
OBJ = $(SRC:.c=.o)
HEADERS = push_swap.h ./libft/libft.h

all: $(LIB_A) $(NAME)

$(LIB_A) :
	$(MAKE) -C $(LIB_DIR) all -s

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIB_DIR) clean -s
	rm -f $(OBJ)


fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean -s
	rm -f $(NAME)


re: fclean all


.PHONY: all clean fclean re
