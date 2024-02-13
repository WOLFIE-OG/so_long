# Define colors
YELLOW=\033[1;33m
RED=\033[1;31m
GREEN=\033[1;32m
BLUE=\033[0;34m
NC=\033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long

SRC_DIR = src
OBJ_DIR = obj
LIBS_D = libs
INC_DIR = include
LIBFT_D = $(LIBS_D)/libft
MINI_LX_D = $(LIBS_D)/minilibx

SRCS = $(SRC_DIR)/main.c
OBJS = $(OBJ_DIR)/main.o

MINI_LX = $(MINI_LX_D)/libmlx.a
LIBFT = $(LIBFT_D)/build/libft.a
LIBS = -L$(LIBFT_D)/build -lft -L$(MINI_LX_D) -lmlx

HEADERS = -I$(INC_DIR) -I$(LIBFT_D) -I$(MINI_LX_D)

all: dir $(MINI_LX) $(NAME)

$(MINI_LX):
	@echo "[$(BLUE)SO_LONG$(NC)]   Building minilibX..."
	@$(MAKE) -s -C $(MINI_LX_D)

dir:
	@if [ ! -d "obj" ]; then \
		echo "[$(GREEN)SO_LONG$(NC)]   Creating obj directory..."; \
		mkdir -p obj; \
	fi

$(NAME): $(LIBFT) $(OBJS)
	@echo "[$(GREEN)SO_LONG$(NC)]   Building $@..."
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/so_long.h
	@echo "[$(GREEN)SO_LONG$(NC)]   Compiling $< --> $@"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c $(INC_DIR)/so_long.h| $(OBJ_DIR)
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
