/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:06:06 by otodd             #+#    #+#             */
/*   Updated: 2024/02/16 15:03:38 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	random_2(int min, int max)
{
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}


void	free_sprites(t_ctx *ctx)
{
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->down_alt);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->down);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->idle);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->left_alt);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->left);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->right_alt );
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->right);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->up_alt);
	ctx->des_i(ctx->mlx_ctx, ctx->player->sprites->up);
	free(ctx->player->sprites);
}

void	free_player(t_ctx *ctx)
{
	free(ctx->player);
}

void	debug_text(t_ctx *ctx)
{
	char	*a;
	char	*b;
	char	*c;
	char	*i;
	char	*j;
	
	i = ft_itoa(ctx->player->x);
	j = ft_itoa(ctx->player->y);
	a = ft_strjoin("X: ", i);
	b = ft_strjoin(" Y: ", j);
	c = ft_strjoin(a, b);
	free(a);
	free(b);
	free(i);
	free(j);
	mlx_string_put(ctx->mlx_ctx, ctx->root, ctx->player->x, ctx->player->y, 0x00bfff, c);
	free(c);
}

int	update(t_ctx *ctx)
{
	if (!ctx->game_running)
		return (0);
	mlx_clear_window(ctx->mlx_ctx, ctx->root);
	debug_text(ctx);
	if (ctx->player->is_alt)
		ctx->player->is_alt = 0;
	else
		ctx->player->is_alt = 1;
	if (ctx->player->direction == 'W')
		up(ctx);
	else if (ctx->player->direction == 'S')
		down(ctx);
	else if (ctx->player->direction == 'A')
		left(ctx);
	else if (ctx->player->direction == 'D')
		right(ctx);
	else
		idle(ctx);
	// usleep(166667);
	ft_printf("%d\n", ctx->player->x);
	usleep(126667);
	return (0);
}

void	close_program(t_ctx *ctx)
{
	mlx_clear_window(ctx->mlx_ctx, ctx->root);
	ctx->game_running = 0;
	mlx_loop_end(ctx->mlx_ctx);
}

int	key_press_handler(int key, t_ctx *ctx)
{
	if (key == KEY_UP)
		ctx->player->direction = 'W';
	else if (key == KEY_DOWN)
		ctx->player->direction = 'S';
	else if (key == KEY_LEFT)
		ctx->player->direction = 'A';
	else if (key == KEY_RIGHT)
		ctx->player->direction = 'D';
	else if (key == ESC)
		close_program(ctx);
	return (0);
}

int	key_release_handler(int key, t_ctx *ctx)
{
	(void)key;
	ctx->player->direction = '0';
	return (0);
}

int	main(void)
{
	t_ctx		*ctx;
	
	ft_printf(GRN"This is so_long!\n"RESET);
	ctx = init_main();
	init_player(ctx);
	mlx_loop_hook(ctx->mlx_ctx, update, ctx);
	mlx_hook(ctx->root, KeyPress, KeyPressMask, key_press_handler, ctx);
	mlx_hook(ctx->root, KeyRelease, KeyReleaseMask, key_release_handler, ctx);
	mlx_loop(ctx->mlx_ctx);
	free_sprites(ctx);
	free_player(ctx);
	mlx_destroy_window(ctx->mlx_ctx, ctx->root);
	mlx_destroy_display(ctx->mlx_ctx);
	free(ctx->mlx_ctx);
	free(ctx);
	return (0);
}