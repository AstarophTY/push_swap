SRCS_DIR := srcs
OBJS_DIR := .objs
DEPS_DIR := .deps

NAME := libft.a
VPATH := srcs:srcs/str:srcs/mem:srcs/link_lst:srcs/is:srcs/io:srcs/printf
BASE_NAME := ft_isalpha \
	  		 ft_isdigit \
	  		 ft_isalnum \
	  		 ft_isascii \
			 ft_isspace \
	  		 ft_isprint \
	  		 ft_strlen \
	  		 ft_memset \
	  		 ft_bzero \
	  		 ft_memcpy \
	  		 ft_memmove \
	  		 ft_strlcpy \
	  		 ft_strlcat \
	  		 ft_toupper \
	  		 ft_tolower \
	  		 ft_strrchr \
	  		 ft_strncmp \
			 ft_strcmp \
	  		 ft_memchr \
	  		 ft_memcmp \
	  		 ft_strnstr \
	  		 ft_atoi \
	  		 ft_calloc \
	  		 ft_strdup \
	  		 ft_substr \
	  		 ft_strjoin \
	  		 ft_split \
	  		 ft_strtrim \
	  		 ft_strchr \
	  		 ft_itoa \
	  		 ft_strmapi \
	  		 ft_striteri \
	  		 ft_putchar_fd \
	  		 ft_putstr_fd \
	  		 ft_putendl_fd \
	  		 ft_putnbr_fd \
	  		 ft_lstnew \
	  		 ft_lstadd_front \
	  		 ft_lstsize \
	  		 ft_lstlast \
	  		 ft_lstadd_back \
	  		 ft_lstdelone \
	  		 ft_lstclear \
	  		 ft_lstiter \
	  		 ft_lstmap \
			 ft_printf \
			 ft_putaddr \
			 ft_putchar \
			 ft_puthex \
			 ft_putnbr \
			 ft_putstr

SRCS := $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(BASE_NAME)))
OBJS := $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(BASE_NAME)))
DEPS := $(addprefix $(DEPS_DIR)/, $(addsuffix .d, $(BASE_NAME)))

CFLAGS := -Werror -Wextra -Wall -g3
CPP_FLAGS := -Iincludes
DEPS_FLAGS := -MP -MD -MF

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c Makefile | $(DEPS_DIR) $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(CPP_FLAGS) $(DEPS_FLAGS) $(DEPS_DIR)/$*.d

$(OBJS_DIR) $(DEPS_DIR):
	mkdir $@

clean:
	$(RM) -r $(DEPS_DIR) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)