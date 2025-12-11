OBJS_DIR := .objs
SRCS_DIR := srcs
DEPS_DIR := .deps
LIBS_DIR := libs

NAME := push_swap
BASE_NAME := main create_list parsing push swap rotate algorithme radix_sort bubble_sort utils chunk_sort chunk_utils selection_sort

VPATH := $(SRCS_DIR):$(SRCS_DIR)/list:$(SRCS_DIR)/parsing:$(SRCS_DIR)/algorithme
SRCS := $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(BASE_NAME)))
OBJS := $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(BASE_NAME)))
DEPS := $(addprefix $(DEPS_DIR)/, $(addsuffix .d, $(BASE_NAME)))

CFLAGS :=  -Wall -Werror -Wextra -g3 # Retirer le g3 a la fin 
CPP_FLAGS := -Iincludes -I$(LIBS_DIR)/libft/includes
DEPS_FLAGS := -MP -MD -MF

LIBFT := $(LIBS_DIR)/libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(OBJS_DIR)/%.o: %.c Makefile | $(OBJS_DIR) $(DEPS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(CPP_FLAGS) $(DEPS_FLAGS) $(DEPS_DIR)/$*.d

$(OBJS_DIR) $(DEPS_DIR):
	mkdir $@

clean:
	$(RM) -r $(OBJS_DIR) $(DEPS_DIR)
	$(MAKE) -C $(LIBS_DIR)/libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBS_DIR)/libft fclean

re: fclean all

force:
$(LIBFT): force
	$(MAKE) -C $(LIBS_DIR)/libft/

.PHONY: all clean fclean re force

-include $(DEPS)