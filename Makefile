# Define colors
YELLOW=\033[1;33m
RED=\033[1;31m
GREEN=\033[1;32m
BLUE=\033[0;34m
NC=\033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = so_long

SRC_DIR = src
OBJ_DIR = obj
LIBS_D = libs
INC_DIR = include
LIBFT_D = $(LIBS_D)/libft
MINI_LX_D = $(LIBS_D)/minilibx

SRCS = 	$(SRC_DIR)/main.c					\
		$(SRC_DIR)/init/game.c				\
		$(SRC_DIR)/init/player.c			\
		$(SRC_DIR)/movement/move.c			\
		$(SRC_DIR)/movement/move_extra.c	\
		$(SRC_DIR)/movement/check_border.c	\
		$(SRC_DIR)/helpers/lps.c			\
		$(SRC_DIR)/memory/sprites.c			\
		$(SRC_DIR)/helpers/offsets.c		\
		$(SRC_DIR)/helpers/key_validator.c	

OBJS = 	$(OBJ_DIR)/main.o					\
		$(OBJ_DIR)/game.o					\
		$(OBJ_DIR)/player.o					\
		$(OBJ_DIR)/move.o					\
		$(OBJ_DIR)/move_extra.o				\
		$(OBJ_DIR)/check_border.o			\
		$(OBJ_DIR)/lps.o					\
		$(OBJ_DIR)/sprites.o				\
		$(OBJ_DIR)/offsets.o				\
		$(OBJ_DIR)/key_validator.o		

MINI_LX = $(MINI_LX_D)/libmlx_Linux.a
LIBFT = $(LIBFT_D)/build/libft.a
LIBS = -L$(LIBFT_D)/build -lft -L$(MINI_LX_D) -lmlx -lXext -lX11 -lm

HEADERS = -I$(INC_DIR) -I$(LIBFT_D) -I$(MINI_LX_D)

all: dir $(MINI_LX) $(NAME)

$(MINI_LX):
	@echo "[$(YELLOW)SO_LONG$(NC)]   Building minilibX..."
	@echo "[======================================================================================]"
	@$(MAKE) -s -C $(MINI_LX_D)
	@echo "[======================================================================================]"
	@echo "[$(BLUE)SO_LONG$(NC)]   Done bulding minilibX..."

dir:
	@if [ ! -d "obj" ]; then \
		echo "[$(GREEN)SO_LONG$(NC)]   Creating obj directory..."; \
		mkdir -p obj; \
	fi

$(NAME): $(LIBFT) $(OBJS)
	@echo "[$(GREEN)SO_LONG$(NC)]   Building $@..."
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "[$(GREEN)SO_LONG$(NC)]   Compiling $< --> $@"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c
	@echo "[$(GREEN)SO_LONG$(NC)]   Compiling $< --> $@"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_D)

clean:
	@echo "[$(YELLOW)SO_LONG$(NC)]   Cleaning object files..."
	@$(MAKE) -s -C $(LIBFT_D) clean
	@$(MAKE) -s -C $(MINI_LX_D) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "[$(YELLOW)SO_LONG$(NC)]   Cleaning executable file..."
	@$(MAKE) -s -C $(LIBFT_D) fclean
	@rm -rf $(NAME)

re: fclean all



.PHONY: all clean fclean re
