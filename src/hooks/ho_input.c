/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ho_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:29:15 by otodd             #+#    #+#             */
/*   Updated: 2024/02/19 14:05:17 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	key_press_handler(int key, t_ctx *ctx)
{
	if (!ctx->game_running)
		return (0);
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
	if (!ctx->game_running)
		return (0);
	if (!key_check(key))
		return (0);
	if (ctx->current_key)
		ctx->current_key -= key;
	ctx->player->direction = '0';
	return (0);
}
