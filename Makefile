OBJS_DIR := .objs
SRCS_DIR := srcs
DEPS_DIR := .deps

NAME := push_swap
BASE_NAME := main

SRCS := $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(BASE_NAME)))
OBJS := $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(BASE_NAME)))
DEPS := $(addprefix $(DEPS_DIR)/, $(addsuffix .d, $(BASE_NAME)))

CFLAGS := -Wall -Werror -Wextra -g3 # Retirer le g3 a la fin
CPP_FLAGS := -Iincludes
DEPS_FLAGS := -MP -MD -MF

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c Makefile | $(OBJS_DIR) $(DEPS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(CPP_FLAGS) $(DEPS_FLAGS) $(DEPS_DIR)/$*.d

$(OBJS_DIR) $(DEPS_DIR):
	mkdir $@

clean:
	$(RM) -r $(OBJS_DIR) $(DEPS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re