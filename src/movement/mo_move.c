/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mo_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:12:29 by otodd             #+#    #+#             */
/*   Updated: 2024/03/15 12:48:38 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	idle(t_ctx *c)
{
	render_idle(c);
}

void	left(t_ctx *c, bool render)
{
	t_vector2	*tl;

	if (!c->player->is_awake)
	{
		put_img(c, c->sprites[AWAKE]);
		c->player->is_awake = true;
		return ;
	}
	tl = c->player->current_tile->map_pos;
	c->player->is_tired = false;
	c->player->played_anim = false;
	c->world->exit_msg = false;
	c->player->sleep_frames_counter = 0;
	time(&c->player->last_active_time);
	if (c->world->tiles[tl->y][tl->x - 1].type != T_WALL)
	{
		c->player->current_tile = &c->world->tiles[tl->y][tl->x - 1];
		c->player->win_pos->x = c->player->current_tile->win_pos->x;
		c->player->moves++;
	}
	if (render)
		render_left(c);
}

void	right(t_ctx *c, bool render)
{
	t_vector2	*tl;

	if (!c->player->is_awake)
	{
		put_img(c, c->sprites[AWAKE]);
		c->player->is_awake = true;
		return ;
	}
	tl = c->player->current_tile->map_pos;
	c->player->is_tired = false;
	c->player->played_anim = false;
	c->world->exit_msg = false;
	c->player->sleep_frames_counter = 0;
	time(&c->player->last_active_time);
	if (c->world->tiles[tl->y][tl->x + 1].type != T_WALL)
	{
		c->player->current_tile = &c->world->tiles[tl->y][tl->x + 1];
		c->player->win_pos->x = c->player->current_tile->win_pos->x;
		c->player->moves++;
	}
	if (render)
		render_right(c);
}

void	up(t_ctx *c, bool render)
{
	t_vector2	*tl;

	if (!c->player->is_awake)
	{
		put_img(c, c->sprites[AWAKE]);
		c->player->is_awake = true;
		return ;
	}
	tl = c->player->current_tile->map_pos;
	c->player->is_tired = false;
	c->player->played_anim = false;
	c->world->exit_msg = false;
	c->player->sleep_frames_counter = 0;
	time(&c->player->last_active_time);
	if (c->world->tiles[tl->y - 1][tl->x].type != T_WALL)
	{
		c->player->current_tile = &c->world->tiles[tl->y - 1][tl->x];
		c->player->win_pos->y = c->player->current_tile->win_pos->y;
		c->player->moves++;
	}
	if (render)
		render_up(c);
}

void	down(t_ctx *c, bool render)
{
	t_vector2	*tl;

	if (!c->player->is_awake)
	{
		put_img(c, c->sprites[AWAKE]);
		c->player->is_awake = true;
		return ;
	}
	tl = c->player->current_tile->map_pos;
	c->player->is_tired = false;
	c->player->played_anim = false;
	c->world->exit_msg = false;
	c->player->sleep_frames_counter = 0;
	time(&c->player->last_active_time);
	if (c->world->tiles[tl->y + 1][tl->x].type != T_WALL)
	{
		c->player->current_tile = &c->world->tiles[tl->y + 1][tl->x];
		c->player->win_pos->y = c->player->current_tile->win_pos->y;
		c->player->moves++;
	}
	if (render)
		render_down(c);
}
