NAME	:=	so_long

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -Wunreachable-code -Ofast
HEADERS	=	-Iinclude -Ilibft -IMLX42/include
LIBS	=	-Llibft -lft -lm -LMLX42/build -lmlx42 -ldl -lglfw -pthread

VPATH	:=	src
SRC		=	main.c init.c loop.c input.c draw.c tilemap.c player_process.c \
			collision.c

OBJ_DIR	:=	obj
OBJ		:=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))


all: libmlx $(NAME)

$(NAME): $(OBJ) | libft
	@$(CC) $(CFLAGS) $(HEADERS) $^ -o $@ $(LIBS)
	@echo "[$(NAME)] Created binary."

$(OBJ_DIR)/%.o: %.c
	@if [ ! -d "$(OBJ_DIR)" ]; then \
		mkdir $(OBJ_DIR); \
	fi
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "[$(NAME)] Compiled $<."

libft:
	@make -C libft

libmlx:
	@if [ ! -d "MLX42" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git; \
		cmake MLX42 -B MLX42/build && make -C MLX42/build -j4; \
	fi

clean:
	@make -C libft clean
	@if [ -d "MLX42" ]; then \
		rm -rf MLX42; \
		echo "[$(NAME)] Removed MiniLibX."; \
	fi
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		echo "[$(NAME)] Removed object files."; \
	fi

fclean: clean
	@make -C libft fclean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "[$(NAME)] Removed binary."; \
	fi

re:	fclean all

.PHONY: all libft libmlx clean fclean re
