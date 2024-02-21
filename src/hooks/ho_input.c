/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ho_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:29:15 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 22:34:00 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	key_press_handler(int key, t_ctx *c)
{
	if (!c->game_running)
		return (0);
	if (!key_check(key))
		return (0);
	c->current_key += key;
	if (c->current_key == KEY_UP)
		c->player->direction = UP;
	else if (c->current_key == KEY_DOWN)
		c->player->direction = DOWN;
	else if (c->current_key == KEY_LEFT)
		c->player->direction = LEFT;
	else if (c->current_key == KEY_RIGHT)
		c->player->direction = RIGHT;
	else if (c->current_key == KEY_UP + KEY_LEFT)
		c->player->direction = UP_LEFT;
	else if (c->current_key == KEY_UP + KEY_RIGHT)
		c->player->direction = UP_RIGHT;
	else if (c->current_key == KEY_DOWN + KEY_LEFT)
		c->player->direction = DOWN_LEFT;
	else if (c->current_key == KEY_DOWN + KEY_RIGHT)
		c->player->direction = DOWN_RIGHT;
	else if (c->current_key == ESC)
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
	c->player->direction = '0';
	return (0);
}
