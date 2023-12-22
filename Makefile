# declare makefile variables
NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# libft path and flags
LIBFT = libft.a
LIB_DIR = ./libft
LIB_FLAGS = -L $(LIB_DIR) -lft

# push_swap targets
# sort_advanced_utils.c
TARGET = main.c verify_params.c stack_utils.c \
	op_swap.c op_push.c op_rotate.c \
	sequence.c sequence_utils.c move_cost.c moves.c \
	sort_index.c sort_simple.c sort_advanced.c \
	exit_utils.c print_stacks.c
SRCS = $(addprefix srcs/, $(TARGET))
BONUS_TARGET = main_bonus.c verify_params_bonus.c stack_utils_bonus.c \
	op_swap_bonus.c op_push_bonus.c op_rotate_bonus.c \
	sort_index_bonus.c checker_bonus.c \
	exit_utils_bonus.c print_stacks_bonus.c
BONUS_SRCS = $(addprefix srcs_bonus/, $(BONUS_TARGET))
INC = -I ./includes

# colours
GREEN = \033[0;32m
B_GREEN = \033[1;32m
BROWN = \033[0;33m
B_BROWN = \033[1;33m
END = \033[0m

# RULES
# all = create library from sub-make

all: $(LIBFT) $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	@echo "\n$(B_BROWN)[ COMPILING: $(NAME) ]$(END)"
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIB_FLAGS) $(INC)
	@echo "$(B_GREEN)$(NAME) compiled.$(END)"

$(LIBFT):
	@echo "\n$(B_BROWN)[ COMPILING: $(LIBFT) ]$(END)"
	@make -s -C $(LIB_DIR)

bonus: $(BONUS_SRCS)
	@echo "\n$(B_BROWN)[ COMPILING: $(BONUS) ]$(END)"
	@$(CC) $(CFLAGS) $(BONUS_SRCS) -o $(BONUS) $(LIB_FLAGS) $(INC)
	@echo "$(B_GREEN)$(BONUS) compiled.$(END)"

# remove temporary generated files
clean:
	@make clean -s -C $(LIB_DIR)

# remove library and executable file
fclean: clean
	@$(RM) $(NAME) $(BONUS)
	@cd $(LIB_DIR) && $(RM) $(LIBFT)
	@echo "$(B_GREEN)Removed $(NAME), $(BONUS) and $(LIBFT).$(END)"

re: fclean all

# declare phony
.PHONY: all bonus clean fclean re
