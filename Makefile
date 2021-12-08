NAME := push_swap

CC := gcc

CFLAGS := -Wall -Wextra -Werror -fsanitize=address

OBJ_DIR := obj

INCLUDES := -I includes/

HEADERS := includes/push_swap.h

SRC := main.c \
		algo.c \
		ft_check_args.c \
		ft_free_arr.c \
		ft_is_sorted.c \
		validate.c

LIB := -L ./42-libft -lft

OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	$(MAKE) -C ./42-libft all bonus
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIB) -o $(NAME)

clean:
	$(MAKE) -C ./42-libft clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) -C ./42-libft fclean
	$(RM) $(NAME)

re: fclean all

commit:
	git commit -m "update push_swap"
	git push origin main

.PHONY: all clean fclean re
