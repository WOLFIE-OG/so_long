# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 12:14:04 by otodd             #+#    #+#              #
#    Updated: 2024/03/26 17:24:54 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW			= 	\033[1;33m
RED				= 	\033[1;31m
GREEN			= 	\033[1;32m
BLUE			= 	\033[1;34m
CYAN			= 	\033[1;36m
NC				= 	\033[0m

CC 				= 	cc
CFLAGS 			= 	-Wall -Wextra -Werror -g
NAME 			= 	so_long

SRC_DIR 		= 	src
OBJ_DIR 		= 	obj
BUILD_DIR		=	build
LIBS_D 			= 	libs
INC_DIR 		= 	include
LIBFT_D 		= 	$(LIBS_D)/libft
MINI_LX_D 		= 	$(LIBS_D)/minilibx

INIT_DIR		= 	$(SRC_DIR)/init
MOVEMENT_DIR 	= 	$(SRC_DIR)/movement
HELPERS_DIR 	= 	$(SRC_DIR)/helpers
MEMORY_DIR 		= 	$(SRC_DIR)/memory
HOOKS_DIR 		= 	$(SRC_DIR)/hooks
MAP_DIR 		= 	$(SRC_DIR)/map
CHECKS_DIR      = 	$(SRC_DIR)/checks
RENDERING_DIR	= 	$(SRC_DIR)/rendering

INIT_OBJ		= 	$(OBJ_DIR)/init
MOVEMENT_OBJ 	= 	$(OBJ_DIR)/movement
HELPERS_OBJ 	= 	$(OBJ_DIR)/helpers
MEMORY_OBJ 		= 	$(OBJ_DIR)/memory
HOOKS_OBJ 		= 	$(OBJ_DIR)/hooks
MAP_OBJ 		= 	$(OBJ_DIR)/map
CHECKS_OBJ      = 	$(OBJ_DIR)/checks
RENDERING_OBJ	= 	$(OBJ_DIR)/rendering

OBJ_DIRS 		= 	$(OBJ_DIR)													\
					$(INIT_OBJ)													\
					$(MOVEMENT_OBJ) 											\
					$(HELPERS_OBJ)												\
					$(MEMORY_OBJ)												\
					$(HOOKS_OBJ)												\
					$(MAP_OBJ)													\
					$(CHECKS_OBJ)												\
					$(RENDERING_OBJ)

INIT_SRCS 		=	$(INIT_DIR)/i_main.c										\
					$(INIT_DIR)/i_mlx.c											\
					$(INIT_DIR)/i_player.c										\
					$(INIT_DIR)/i_world.c										\
					$(INIT_DIR)/i_map.c											\
					$(INIT_DIR)/i_sleeping_frames.c 							\
					$(INIT_DIR)/i_ui.c 											\
					$(INIT_DIR)/i_sprite_table.c

MOVMENT_SRCS	=	$(MOVEMENT_DIR)/mo_move.c									\
			  		$(MOVEMENT_DIR)/mo_move_extra.c

HELPERS_SRCS	=	$(HELPERS_DIR)/h_img_loader.c								\
			  		$(HELPERS_DIR)/h_dimensions.c								\
			  		$(HELPERS_DIR)/h_variant_name.c

MEMORY_SRCS		=	$(MEMORY_DIR)/m_buffer.c 									\
			  		$(MEMORY_DIR)/m_sprites.c									\
			  		$(MEMORY_DIR)/m_player.c 									\
			  		$(MEMORY_DIR)/m_world.c										\
			  		$(MEMORY_DIR)/m_destroy.c 									\
			  		$(MEMORY_DIR)/m_tiles.c 									\
			  		$(MEMORY_DIR)/m_map.c

HOOKS_SRCS		=	$(HOOKS_DIR)/ho_input.c										\
			  		$(HOOKS_DIR)/ho_update.c									\
			  		$(HOOKS_DIR)/ho_close.c										\

MAP_SRCS		=	$(MAP_DIR)/ma_load.c										\
			  		$(MAP_DIR)/ma_parse.c

CHECKS_SRCS		=  	$(CHECKS_DIR)/c_check_images.c								\
			  		$(CHECKS_DIR)/c_map.c										\
			  		$(CHECKS_DIR)/c_idle.c										\
			  		$(CHECKS_DIR)/c_tiles.c										\
			  		$(CHECKS_DIR)/c_paths.c										\
			  		$(CHECKS_DIR)/c_keys.c 										\
			  		$(CHECKS_DIR)/c_check_border.c

RENDERING_SRCS	=	$(RENDERING_DIR)/r_world.c									\
			  		$(RENDERING_DIR)/r_borders.c								\
			  		$(RENDERING_DIR)/r_player.c									\
			  		$(RENDERING_DIR)/r_player_extra.c							\
			  		$(RENDERING_DIR)/r_ui.c

OBJS 			= 	$(OBJ_DIR)/init.o											\
					$(INIT_SRCS:$(INIT_DIR)/%.c=$(INIT_OBJ)/%.o)				\
					$(MOVMENT_SRCS:$(MOVEMENT_DIR)/%.c=$(MOVEMENT_OBJ)/%.o)		\
					$(HELPERS_SRCS:$(HELPERS_DIR)/%.c=$(HELPERS_OBJ)/%.o)		\
					$(MEMORY_SRCS:$(MEMORY_DIR)/%.c=$(MEMORY_OBJ)/%.o)			\
					$(HOOKS_SRCS:$(HOOKS_DIR)/%.c=$(HOOKS_OBJ)/%.o)				\
					$(MAP_SRCS:$(MAP_DIR)/%.c=$(MAP_OBJ)/%.o)					\
					$(CHECKS_SRCS:$(CHECKS_DIR)/%.c=$(CHECKS_OBJ)/%.o)			\
					$(RENDERING_SRCS:$(RENDERING_DIR)/%.c=$(RENDERING_OBJ)/%.o)	\


MINI_LX = $(MINI_LX_D)/libmlx_Linux.a
LIBFT = $(LIBFT_D)/build/libft.a
LIBS = -L$(LIBFT_D)/build -lft -L$(MINI_LX_D) -lmlx -lXext -lX11

HEADERS = -I$(INC_DIR) -I$(MINI_LX_D)

all: dir $(MINI_LX) $(NAME)

$(MINI_LX):
	@echo "[$(BLUE)SO_LONG$(NC)]   Building minilibX..."
	@echo "[======================================================================================]"
	@$(MAKE) -s -C $(MINI_LX_D)
	@echo "[======================================================================================]"
	@echo "[$(BLUE)SO_LONG$(NC)]   Done bulding minilibX..."

dir:
	@for dir in $(OBJ_DIRS) $(BUILD_DIR); do 									\
		if [ ! -d "$$dir" ]; then												\
			echo "[$(GREEN)SO_LONG$(NC)]   Creating obj directory: $$dir"; 		\
			mkdir -p $$dir; 													\
		fi; 																	\
	done

$(NAME): $(LIBFT) $(OBJS)
	@echo "[$(BLUE)SO_LONG$(NC)]   Building $@..."
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) $(LIBS) -o $(NAME)

$(OBJ_DIR)/init.o: $(SRC_DIR)/init.c
	@echo "[$(CYAN)SO_LONG$(NC)]   Compiling main program $< --> $@"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(INIT_OBJ)/%.o: $(INIT_DIR)/%.c
	@echo "[$(CYAN)SO_LONG$(NC)]   Compiling $< --> $@ from $(INIT_DIR)"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(MOVEMENT_OBJ)/%.o: $(MOVEMENT_DIR)/%.c
	@echo "[$(CYAN)SO_LONG$(NC)]   Compiling $< --> $@ from $(MOVEMENT_DIR)"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(HELPERS_OBJ)/%.o: $(HELPERS_DIR)/%.c
	@echo "[$(CYAN)SO_LONG$(NC)]   Compiling $< --> $@ from $(HELPERS_DIR)"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(MEMORY_OBJ)/%.o: $(MEMORY_DIR)/%.c
	@echo "[$(CYAN)SO_LONG$(NC)]   Compiling $< --> $@ from $(MEMORY_DIR)"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(HOOKS_OBJ)/%.o: $(HOOKS_DIR)/%.c
	@echo "[$(CYAN)SO_LONG$(NC)]   Compiling $< --> $@ from $(HOOKS_DIR)"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(MAP_OBJ)/%.o: $(MAP_DIR)/%.c
	@echo "[$(CYAN)SO_LONG$(NC)]   Compiling $< --> $@ from $(MAP_DIR)"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(CHECKS_OBJ)/%.o: $(CHECKS_DIR)/%.c
	@echo "[$(CYAN)SO_LONG$(NC)]   Compiling $< --> $@ from $(CHECKS_DIR)"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(RENDERING_OBJ)/%.o: $(RENDERING_DIR)/%.c
	@echo "[$(CYAN)SO_LONG$(NC)]   Compiling $< --> $@ from $(RENDERING_DIR)"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_D)

clean:
	@echo "[$(YELLOW)SO_LONG$(NC)]   Cleaning object directory..."
	@$(MAKE) -s -C $(LIBFT_D) clean
	@$(MAKE) -s -C $(MINI_LX_D) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "[$(RED)SO_LONG$(NC)]   Cleaning executable directory..."
	@$(MAKE) -s -C $(LIBFT_D) fclean
	@rm -rf $(NAME)

re: fclean all



.PHONY: all clean fclean re
