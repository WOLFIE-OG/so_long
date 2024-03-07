/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ho_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:29:15 by otodd             #+#    #+#             */
/*   Updated: 2024/03/07 18:37:28 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	set_direction(t_ctx *c)
{
	if (c->current_key == KEY_UP)
		c->player->direction = M_UP;
	else if (c->current_key == KEY_DOWN)
		c->player->direction = M_DOWN;
	else if (c->current_key == KEY_LEFT)
		c->player->direction = M_LEFT;
	else if (c->current_key == KEY_RIGHT)
		c->player->direction = M_RIGHT;
	else if (c->current_key == KEY_UP + KEY_LEFT)
		c->player->direction = M_UP_LEFT;
	else if (c->current_key == KEY_UP + KEY_RIGHT)
		c->player->direction = M_UP_RIGHT;
	else if (c->current_key == KEY_DOWN + KEY_LEFT)
		c->player->direction = M_DOWN_LEFT;
	else if (c->current_key == KEY_DOWN + KEY_RIGHT)
		c->player->direction = M_DOWN_RIGHT;
	else
		c->player->direction = M_IDLE;
}

int	key_press_handler(int key, t_ctx *c)
{
	if (!c->game_running)
		return (0);
	if (!key_check(key))
		return (0);
	c->current_key += key;
	set_direction(c);
	if (c->current_key == ESC)
		close_program(c);
	return (0);
}

int	key_release_handler(int key, t_ctx *c)
{
	if (!c->game_running)
		return (0);
	if (!key_check(key))
		return (0);
	if (c->current_key)
		c->current_key -= key;
	set_direction(c);
	return (0);
}
