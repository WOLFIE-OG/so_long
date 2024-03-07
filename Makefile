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

SRCS = 	$(SRC_DIR)/init.c						\
		$(SRC_DIR)/init/i_main.c				\
		$(SRC_DIR)/init/i_mlx.c					\
		$(SRC_DIR)/init/i_player.c				\
		$(SRC_DIR)/init/i_world.c				\
		$(SRC_DIR)/init/i_vector.c				\
		$(SRC_DIR)/init/i_map.c					\
		$(SRC_DIR)/init/i_sleeping_frames.c 	\
		$(SRC_DIR)/init/i_ui.c 					\
		$(SRC_DIR)/init/i_sprite_table.c 		\
		$(SRC_DIR)/movement/mo_move.c			\
		$(SRC_DIR)/movement/mo_move_extra.c		\
		$(SRC_DIR)/helpers/h_img_loader.c		\
		$(SRC_DIR)/helpers/h_dimensions.c		\
		$(SRC_DIR)/helpers/h_variant_name.c		\
		$(SRC_DIR)/memory/m_buffer.c 			\
		$(SRC_DIR)/memory/m_sprites.c			\
		$(SRC_DIR)/memory/m_player.c 			\
		$(SRC_DIR)/memory/m_world.c				\
		$(SRC_DIR)/memory/m_destroy.c 			\
		$(SRC_DIR)/memory/m_tiles.c 			\
		$(SRC_DIR)/memory/m_map.c 				\
		$(SRC_DIR)/hooks/ho_input.c				\
		$(SRC_DIR)/hooks/ho_update.c			\
		$(SRC_DIR)/hooks/ho_close.c				\
		$(SRC_DIR)/map/ma_load.c				\
		$(SRC_DIR)/map/ma_parse.c				\
		$(SRC_DIR)/checks/c_check_images.c		\
		$(SRC_DIR)/checks/c_map.c				\
		$(SRC_DIR)/checks/c_idle.c				\
		$(SRC_DIR)/checks/c_tiles.c				\
		$(SRC_DIR)/checks/c_paths.c				\
		$(SRC_DIR)/checks/c_keys.c 				\
		$(SRC_DIR)/checks/c_check_border.c		\
		$(SRC_DIR)/rendering/r_world.c			\
		$(SRC_DIR)/rendering/r_borders.c		\
		$(SRC_DIR)/rendering/r_player.c			\
		$(SRC_DIR)/rendering/r_player_extra.c	\
		$(SRC_DIR)/rendering/r_ui.c

OBJS = 	$(OBJ_DIR)/init.o						\
		$(OBJ_DIR)/i_main.o						\
		$(OBJ_DIR)/i_mlx.o						\
		$(OBJ_DIR)/i_player.o					\
		$(OBJ_DIR)/i_world.o					\
		$(OBJ_DIR)/i_vector.o 					\
		$(OBJ_DIR)/i_map.o 						\
		$(OBJ_DIR)/i_sleeping_frames.o 			\
		$(OBJ_DIR)/i_sprite_table.o 			\
		$(OBJ_DIR)/i_ui.o						\
		$(OBJ_DIR)/mo_move.o					\
		$(OBJ_DIR)/mo_move_extra.o				\
		$(OBJ_DIR)/h_img_loader.o				\
		$(OBJ_DIR)/h_dimensions.o				\
		$(OBJ_DIR)/h_variant_name.o 			\
		$(OBJ_DIR)/m_buffer.o 					\
		$(OBJ_DIR)/m_sprites.o					\
		$(OBJ_DIR)/m_player.o 					\
		$(OBJ_DIR)/m_world.o					\
		$(OBJ_DIR)/m_destroy.o		 			\
		$(OBJ_DIR)/m_tiles.o 					\
		$(OBJ_DIR)/m_map.o 						\
		$(OBJ_DIR)/ho_input.o					\
		$(OBJ_DIR)/ho_update.o					\
		$(OBJ_DIR)/ho_close.o					\
		$(OBJ_DIR)/ma_load.o					\
		$(OBJ_DIR)/ma_parse.o					\
		$(OBJ_DIR)/c_check_images.o				\
		$(OBJ_DIR)/c_map.o 						\
		$(OBJ_DIR)/c_idle.o 					\
		$(OBJ_DIR)/c_tiles.o					\
		$(OBJ_DIR)/c_paths.o 					\
		$(OBJ_DIR)/c_keys.o 					\
		$(OBJ_DIR)/c_check_border.o				\
		$(OBJ_DIR)/r_world.o					\
		$(OBJ_DIR)/r_borders.o					\
		$(OBJ_DIR)/r_player.o					\
		$(OBJ_DIR)/r_player_extra.o				\
		$(OBJ_DIR)/r_ui.o

MINI_LX = $(MINI_LX_D)/libmlx_Linux.a
LIBFT = $(LIBFT_D)/build/libft.a
LIBS = -L$(LIBFT_D)/build -lft -L$(MINI_LX_D) -lmlx -lXext -lX11

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
