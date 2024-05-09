NAME	:=	so_long

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
HEADERS	=	-Iinclude -Ilibft -Imlx
LIBS	=	-Llibft -lft -lm -Lmlx -lmlx
FRMWRKS	=	-framework OpenGL -framework AppKit

VPATH	:=	src
SRC		=	main.c init.c loop.c input.c

OBJ_DIR	:=	obj
OBJ		:=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))


all: $(NAME)

$(NAME): $(OBJ) | libft mlx
	@$(CC) $(CFLAGS) $(HEADERS) $^ -o $@ $(LIBS) $(FRMWRKS)
	@echo "[$(NAME)] Created binary."

$(OBJ_DIR)/%.o: %.c
	@if [ ! -d "$(OBJ_DIR)" ]; then \
		mkdir $(OBJ_DIR); \
	fi
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "[$(NAME)] Compiled $<."

libft:
	@make -C libft

mlx:
	@make -C mlx

clean:
	@make -C libft clean
	@make -C mlx clean
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

.PHONY: all libft mlx clean fclean re
