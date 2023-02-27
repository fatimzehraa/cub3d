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
		lists/ft_lstadd_back.o lists/ft_lstadd_front.o lists/ft_lstclear.o lists/ft_lstdelone.o lists/ft_lstiter.o \
		lists/ft_lstlast.o lists/ft_lstmap.o lists/ft_lstnew.o lists/ft_lstsize.o \
		get_next_line/get_next_line.o get_next_line/get_next_line_utils.o \
		parsing/check_map.o parsing/parse.o parsing/parse_utils.o
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
