/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ho_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:29:15 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 18:35:09 by otodd            ###   ########.fr       */
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
		c->player->direction = 'W';
	else if (c->current_key == KEY_DOWN)
		c->player->direction = 'S';
	else if (c->current_key == KEY_LEFT)
		c->player->direction = 'A';
	else if (c->current_key == KEY_RIGHT)
		c->player->direction = 'D';
	else if (c->current_key == KEY_UP + KEY_LEFT)
		c->player->direction = '1';
	else if (c->current_key == KEY_UP + KEY_RIGHT)
		c->player->direction = '2';
	else if (c->current_key == KEY_DOWN + KEY_LEFT)
		c->player->direction = '3';
	else if (c->current_key == KEY_DOWN + KEY_RIGHT)
		c->player->direction = '4';
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
