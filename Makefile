NAME := push_swap

CC := gcc

CFLAGS := -Wall -Wextra -Werror -fsanitize=address

OBJ_DIR := obj

INCLUDES := -I includes/

HEADERS := includes/push_swap.h

SRC := main.c \
		$(addprefix utils/, \
		algo.c \
		ft_check_args.c \
		ft_free_arr.c \
		ft_init_stacks.c \
		ft_is_sorted.c \
		operations.c \
		both_operations.c \
		validate.c) \
		$(addprefix utils/linked_list/, \
		ft_lladd_back.c \
		ft_lladd_front.c \
		ft_llclear.c \
		ft_lllast.c \
		ft_llnew.c \
		ft_llsize.c)

LIB := -L ./42-libft -lft

OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/utils/linked_list
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	$(MAKE) -C ./42-libft all
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
