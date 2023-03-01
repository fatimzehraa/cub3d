CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LDFLAGS = -lmlx -lXext -lX11 -lm -lbsd
endif
ifeq ($(UNAME_S),Darwin)
	LDFLAGS = -lmlx -framework OpenGL -framework AppKit
endif
#LDFLAGS += -fsanitize=address

BUILD_DIR = build
HEADER_FILES = cub3D.h get_next_line.h list.h
INCLUDES = $(addprefix inc/, $(HEADER_FILES))
INC = -I inc -I/usr/local/include
FILES = main.o \
		lib/ft_atoi.o lib/ft_bzero.o lib/ft_calloc.o lib/ft_isalnum.o lib/ft_isalpha.o lib/ft_isascii.o lib/ft_isprint.o \
		lib/ft_itoa.o lib/ft_memchr.o lib/ft_memcmp.o lib/ft_memcpy.o lib/ft_memmove.o lib/ft_memset.o \
		lib/ft_putchar_fd.o lib/ft_putendl_fd.o lib/ft_putnbr_fd.o lib/ft_putstr_fd.o \
		lib/ft_split.o lib/ft_strchr.o lib/ft_strdup.o lib/ft_striteri.o lib/ft_strjoin.o lib/ft_strlcat.o lib/ft_strlcpy.o \
		lib/ft_strlen.o lib/ft_strmapi.o lib/ft_strncmp.o lib/ft_strnstr.o lib/ft_strrchr.o lib/ft_strtrim.o \
		lib/ft_substr.o lib/ft_tolower.o lib/ft_toupper.o \
		lists/ft_lstadd_back.o lists/ft_lstadd_front.o lists/ft_lstclear.o lists/ft_lstdelone.o lists/ft_lstiter.o \
		lists/ft_lstlast.o lists/ft_lstmap.o lists/ft_lstnew.o lists/ft_lstsize.o \
		get_next_line/get_next_line.o get_next_line/get_next_line_utils.o \
		parsing/check_map.o parsing/parse.o parsing/parse_utils.o parsing/parse_textures.o
OBG = $(addprefix $(BUILD_DIR)/, $(FILES))
#OBG = $(addprefix $(BUILD_DIR)/, $(FILES))

NAME = cub3D

all: $(NAME)

$(NAME): $(OBG)
	$(CC) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: src/%.c $(INCLUDES)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(OBG)
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
