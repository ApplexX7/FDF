OS := $(shell uname)

ifeq ($(OS), Darwin)  # macOS
	MLXFLAGS := -lmlx -framework OpenGL -framework AppKit
	INCLUDE_DIR := ./MacOs_Include
	MLX_LIB := ./minilibx_macos
	CFLAGS += -D OS_MAC
else  # Linux
	MLXFLAGS := -Lminilibx-linux -lmlx -lX11 -lXext -lm
	INCLUDE_DIR := ./Linux_Include
	MLX_LIB := ./minilibx-linux
	CFLAGS += -D OS_LINUX
endif

SRC_DIR = src/

SRC = fdf.c fdf_parsing.c fdf_utils_one.c \
	fdf_utils_two.c fdf_utils.c fdf_utils_tree.c \
	fdf_grad_color.c fdf_brehensman.c fdf_draw.c \
	fdf_parsing_sec.c fdf_utils_four.c fdf_rotation.c \
	fdf_isoproject.c fdf_centre.c fdf_keybord.c \
	fdf_iniate.c fdf_keybordsec.c fdf_menu.c

CC = cc 
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
BUILD_DIR = ./build
OBJCT = $(SRC:%.c=$(BUILD_DIR)/%.o)

RM = rm -rf
NAME = FDF

HEADER_NAME = ./$(INCLUDE_DIR)/fdf.h

all : Fdf $(NAME)

Fdf:
	@[ -d "$(BUILD_DIR)" ] || mkdir "$(BUILD_DIR)"
	@echo "\033[1;35m"  # Changed to magenta for text art
	@echo "███████╗██████╗ ███████╗"
	@echo "██╔════╝██╔══██╗██╔════╝"
	@echo "█████╗  ██║  ██║█████╗  "
	@echo "██╔══╝  ██║  ██║██╔══╝  "
	@echo "██║     ██████╔╝██║     "
	@echo "╚═╝     ╚═════╝ ╚═╝     "
	@echo "\033[0m"  # Reset to default color
	@echo "\033[0;34mCompiling \033[1;34mminilibx"
	@$(MAKE) -C $(MLX_LIB)

$(NAME) : $(OBJCT)
	@$(CC) $(CFLAGS) $(OBJCT) $(MLXFLAGS) -o $(NAME)
	@echo "\033[1;34m$(NAME) \033[0;34mhas been compiled"

$(BUILD_DIR)/%.o : $(SRC_DIR)%.c $(HEADER_NAME)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJCT)
	@$(MAKE) clean -C $(MLX_LIB)

fclean : clean
	@$(RM) $(NAME) $(BUILD_DIR)
	@echo "\033[1;34m$(NAME) \033[0;34mFDF has been cleaned"

re : fclean all

DOCKER_IMAGE := fdf:0.1

build-docker:
	@docker build -t $(DOCKER_IMAGE) .

run-docker: build-docker
	@docker run -it --rm \
		-e DISPLAY=$(DISPLAY) \
		-v /tmp/.X11-unix:/tmp/.X11-unix \
		$(DOCKER_IMAGE)

.PHONY: all clean fclean re lib build-docker run-docker
