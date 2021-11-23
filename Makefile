NAME := push_swap

CC := clang

CFLAGS := -Wall -Wextra -Werror -g

OBJ_DIR := obj

INCLUDES := -I includes/

HEADERS := includes/push_swap.h

SRC := main.c \
		free.c \
		ft_check_args.c \
		validate.c

LIB := -L ./42-libft -lft

OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	$(MAKE) -C ./42-libft
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