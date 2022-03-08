NAME := push_swap

CC := gcc

CFLAGS := -Wall -Wextra -Werror -fsanitize=address

OBJ_DIR := obj

INCLUDES := -I includes/

HEADERS := includes/push_swap.h

SRC := main.c \
		$(addprefix utils/, \
		ft_algorithm.c \
		ft_free_arr.c \
		ft_init_stacks.c \
		ft_is_sorted.c \
		ft_sort_arr.c \
		operations_2stack.c \
		operations.c \
		parser.c \
		validate.c) \
		$(addprefix utils/linked_list/, \
		ft_lladd_back.c \
		ft_lladd_front.c \
		ft_llclear.c \
		ft_lllast.c \
		ft_llnew.c \
		ft_llsize.c)

LIB_DIR := ./42-ft_printf

LIB := $(LIB_DIR)/libftprintf.a

OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/utils/linked_list
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	$(MAKE) -C $(LIB_DIR) all
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIB) -o $(NAME)

clean:
	$(MAKE) -C $(LIB_DIR) clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re: fclean all

commit:
	git commit -m "update push_swap"
	git push origin main

.PHONY: all clean fclean re
