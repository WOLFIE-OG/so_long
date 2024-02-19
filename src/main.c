/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:06:06 by otodd             #+#    #+#             */
/*   Updated: 2024/02/19 12:49:07 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	random_2(int min, int max)
{
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
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
	mlx_string_put(ctx->mlx_ctx, ctx->root, ctx->player->x - 30, ctx->player->y - 40, 0x00bfff, c);
	free(c);
}

void	alt_shift(t_ctx *ctx)
{
	if (ctx->player->is_alt)
		ctx->player->is_alt = 0;
	else
		ctx->player->is_alt = 1;
}

void	extended(t_ctx *ctx)
{
	alt_shift(ctx);
	debug_text(ctx);
}

int	update(t_ctx *ctx)
{
	if (!ctx->game_running)
		return (0);
	mlx_clear_window(ctx->mlx_ctx, ctx->root);
	if (ctx->player->direction == 'W')
		up(ctx);
	else if (ctx->player->direction == 'S')
		down(ctx);
	else if (ctx->player->direction == 'A')
		left(ctx);
	else if (ctx->player->direction == 'D')
		right(ctx);
	else if (ctx->player->direction == '1')
		up_left(ctx);
	else if (ctx->player->direction == '2')
		up_right(ctx);
	else if (ctx->player->direction == '3')
		down_left(ctx);
	else if (ctx->player->direction == '4')
		down_right(ctx);
	else
		idle(ctx);
	extended(ctx);
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
	if (!key_check(key))
		return (0);
	ctx->current_key += key;
	if (ctx->current_key == KEY_UP)
		ctx->player->direction = 'W';
	else if (ctx->current_key == KEY_DOWN)
		ctx->player->direction = 'S';
	else if (ctx->current_key == KEY_LEFT)
		ctx->player->direction = 'A';
	else if (ctx->current_key == KEY_RIGHT)
		ctx->player->direction = 'D';
	else if (ctx->current_key == KEY_UP + KEY_LEFT)
		ctx->player->direction = '1';
	else if (ctx->current_key == KEY_UP + KEY_RIGHT)
		ctx->player->direction = '2';
	else if (ctx->current_key == KEY_DOWN + KEY_LEFT)
		ctx->player->direction = '3';
	else if (ctx->current_key == KEY_DOWN + KEY_RIGHT)
		ctx->player->direction = '4';
	else if (ctx->current_key == ESC)
		close_program(ctx);
	return (0);
}

int	key_release_handler(int key, t_ctx *ctx)
{
	if (!key_check(key))
		return (0);
	if (ctx->current_key)
		ctx->current_key -= key;
	ctx->player->direction = '0';
	return (0);
}

void	load_map(void)
{
	int		map;
	char	*line;

	map = open("./res/maps/map.ber", O_RDONLY);
	while(1)
	{
		line = ft_get_next_line(map);
		if (!line)
			break ;
		ft_printf("%s", line);
		free(line);
	}
}

int	main(void)
{
	t_ctx		*ctx;
	
	load_map();
	ft_printf(GRN"This is so_long!\n"RESET);
	ctx = init_main();
	ctx->current_key = 0;
	init_player(ctx);
	mlx_loop_hook(ctx->mlx_ctx, update, ctx);
	mlx_hook(ctx->root, KeyPress, KeyPressMask, key_press_handler, ctx);
	mlx_hook(ctx->root, KeyRelease, KeyReleaseMask, key_release_handler, ctx);
	mlx_loop(ctx->mlx_ctx);
	free_sprites(ctx);
	free_sprites_extra(ctx);
	free_sprites_extra_extra(ctx);
	free(ctx->player->sprites);
	free_player(ctx);
	mlx_destroy_window(ctx->mlx_ctx, ctx->root);
	mlx_destroy_display(ctx->mlx_ctx);
	free(ctx->mlx_ctx);
	free(ctx);
	return (0);
}