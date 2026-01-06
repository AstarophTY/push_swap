OBJS_DIR := .objs
SRCS_DIR := srcs
DEPS_DIR := .deps
LIBS_DIR := libs

NAME := push_swap
BASE_NAME := main create_list parsing push swap rotate algorithme radix_sort utils chunk_sort chunk_utils selection_sort bench small_sort
BONUS_NAME := checker
BONUS_BASE := checker checker_parsing checker_ops checker_utils push swap rotate utils bench

VPATH := $(SRCS_DIR):$(SRCS_DIR)/list:$(SRCS_DIR)/parsing:$(SRCS_DIR)/algorithme:$(SRCS_DIR)/checker
SRCS := $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(BASE_NAME)))
OBJS := $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(BASE_NAME)))
DEPS := $(addprefix $(DEPS_DIR)/, $(addsuffix .d, $(BASE_NAME)))
BONUS_OBJS := $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(BONUS_BASE)))
BONUS_DEPS := $(addprefix $(DEPS_DIR)/, $(addsuffix .d, $(BONUS_BASE)))

CFLAGS := -Wall -Werror -Wextra
CPP_FLAGS := -Iincludes -I$(LIBS_DIR)/libft/includes
DEPS_FLAGS := -MP -MD -MF

LIBFT := $(LIBS_DIR)/libft/libft.a

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) $(LIBFT)

$(OBJS_DIR)/%.o: %.c Makefile | $(OBJS_DIR) $(DEPS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(CPP_FLAGS) $(DEPS_FLAGS) $(DEPS_DIR)/$*.d

$(OBJS_DIR) $(DEPS_DIR):
	mkdir $@

clean:
	$(RM) -r $(OBJS_DIR) $(DEPS_DIR)
	$(MAKE) -C $(LIBS_DIR)/libft clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBS_DIR)/libft fclean

re: fclean all

force:
$(LIBFT): force
	$(MAKE) -C $(LIBS_DIR)/libft/

.PHONY: all clean fclean re force
-include $(DEPS) $(BONUS_DEPS)