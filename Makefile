CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LDFLAGS = -lmlx -lXext -lX11 -lm -lbsd
endif
ifeq ($(UNAME_S),Darwin)
	LDFLAGS = -lmlx -framework OpenGL -framework AppKit
endif
LDFLAGS += -fsanitize=address

BUILD_DIR = build
HEADER_FILES = #h1.h
INCLUDES = $(addprefix inc/, $(HEADER_FILES))
FILES = src/main.o
OBG = $(addprefix $(BUILD_DIR)/, $(FILES))

NAME = cub3D

all: $(NAME)

$(NAME): $(OBG)
	$(CC) $^ -o $@ $(LDFLAGS)

#%.o: %.c $(INCLUDES)
#	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/src/%.o: src/%.c $(HEADER_FILES)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
