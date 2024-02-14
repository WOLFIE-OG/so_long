/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:06:06 by otodd             #+#    #+#             */
/*   Updated: 2024/02/14 15:15:22 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <time.h> 

int	random_2(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

t_player	*init_player(void *ctx)
{
	t_player_sprites	*sprites;
	t_player			*player;
	int					width = 30;
	int					height = 30;

	sprites = malloc(sizeof(t_player_sprites));
	player = malloc(sizeof(t_player));
	player->sprites = sprites;
	sprites->down_alt = mlx_xpm_file_to_image(ctx, "./res/tex/plr/down_alt.xpm", &width, &height);
	sprites->down = mlx_xpm_file_to_image(ctx, "./res/tex/plr/down.xpm", &width, &height);
	sprites->idle = mlx_xpm_file_to_image(ctx, "./res/tex/plr/idle.xpm", &width, &height);
	sprites->left_alt = mlx_xpm_file_to_image(ctx, "./res/tex/plr/left_alt.xpm", &width, &height);
	sprites->left = mlx_xpm_file_to_image(ctx, "./res/tex/plr/left.xpm", &width, &height);
	sprites->right_alt = mlx_xpm_file_to_image(ctx, "./res/tex/plr/right_alt.xpm", &width, &height);
	sprites->right = mlx_xpm_file_to_image(ctx, "./res/tex/plr/right.xpm", &width, &height);
	sprites->up_alt = mlx_xpm_file_to_image(ctx, "./res/tex/plr/up_alt.xpm", &width, &height);
	sprites->up = mlx_xpm_file_to_image(ctx, "./res/tex/plr/up.xpm", &width, &height);
	return (player);
}

int	draw(t_ctx *ctx)
{
	mlx_put_image_to_window(ctx->mlx_ctx, ctx->root, ctx->player->sprites->down_alt, random_2(0, 500), random_2(0, 500));
	mlx_put_image_to_window(ctx->mlx_ctx, ctx->root, ctx->player->sprites->down, random_2(0, 500), random_2(0, 500));
	mlx_put_image_to_window(ctx->mlx_ctx, ctx->root, ctx->player->sprites->idle, random_2(0, 500), random_2(0, 500));
	mlx_put_image_to_window(ctx->mlx_ctx, ctx->root, ctx->player->sprites->left_alt, random_2(0, 500), random_2(0, 500));
	mlx_put_image_to_window(ctx->mlx_ctx, ctx->root, ctx->player->sprites->left, random_2(0, 500), random_2(0, 500));
	mlx_put_image_to_window(ctx->mlx_ctx, ctx->root, ctx->player->sprites->right_alt, random_2(0, 500), random_2(0, 500));
	mlx_put_image_to_window(ctx->mlx_ctx, ctx->root, ctx->player->sprites->right_alt, random_2(0, 500), random_2(0, 500));
	mlx_put_image_to_window(ctx->mlx_ctx, ctx->root, ctx->player->sprites->up_alt, random_2(0, 500), random_2(0, 500));
	mlx_put_image_to_window(ctx->mlx_ctx, ctx->root, ctx->player->sprites->up, random_2(0, 500), random_2(0, 500));
	return (0);
}

int	main(void)
{
	t_ctx		*ctx;
	
	ft_printf(GRN"This is so_long!\n"RESET);
	ctx = malloc(sizeof(t_ctx));
	ctx->mlx_ctx = mlx_init();
	ctx->player = init_player(ctx->mlx_ctx);
	ctx->root = mlx_new_window(ctx->mlx_ctx, 500, 500, "My test window");
	mlx_loop_hook(ctx->mlx_ctx, draw, ctx);
	mlx_loop(ctx->mlx_ctx);
	return (0);
}