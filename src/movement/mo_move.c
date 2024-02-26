/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mo_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:12:29 by otodd             #+#    #+#             */
/*   Updated: 2024/02/26 16:05:01 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	idle(t_ctx *c)
{
	render_idle(c);
}

void	left(t_ctx *c, bool render)
{
	t_player	*p;
	t_vector2	*tl;

	p = c->player;
	if (!p->is_awake)
	{
		put_img(c, c->player->sprites->awake);
		p->is_awake = true;
		return ;
	}
	tl = p->current_tile->local_pos;
	p->is_tired = false;
	p->played_anim = false;
	c->world->exit_msg = false;
	c->world->easter_egg = false;
	p->sleep_frames_counter = 0;
	time(&p->last_active_time);
	if (c->world->tiles[tl->y][tl->x - 1].type != WALL)
	{
		p->current_tile = &c->world->tiles[tl->y][tl->x - 1];
		c->player->moves++;
	}
	p->pos->x = p->current_tile->pos->x;
	if (render)
		render_left(c);
}

void	right(t_ctx *c, bool render)
{
	t_player	*p;
	t_vector2	*tl;

	p = c->player;
	if (!p->is_awake)
	{
		put_img(c, c->player->sprites->awake);
		p->is_awake = true;
		return ;
	}
	tl = p->current_tile->local_pos;
	p->is_tired = false;
	p->played_anim = false;
	c->world->exit_msg = false;
	c->world->easter_egg = false;
	p->sleep_frames_counter = 0;
	time(&p->last_active_time);
	if (c->world->tiles[tl->y][tl->x + 1].type != WALL)
	{
		p->current_tile = &c->world->tiles[tl->y][tl->x + 1];
		c->player->moves++;
	}
	p->pos->x = p->current_tile->pos->x;
	if (render)
		render_right(c);
}

void	up(t_ctx *c, bool render)
{
	t_player	*p;
	t_vector2	*tl;

	p = c->player;
	if (!p->is_awake)
	{
		put_img(c, c->player->sprites->awake);
		p->is_awake = true;
		return ;
	}
	tl = p->current_tile->local_pos;
	p->is_tired = false;
	p->played_anim = false;
	c->world->exit_msg = false;
	c->world->easter_egg = false;
	p->sleep_frames_counter = 0;
	time(&p->last_active_time);
	if (c->world->tiles[tl->y - 1][tl->x].type != WALL)
	{
		p->current_tile = &c->world->tiles[tl->y - 1][tl->x];
		c->player->moves++;
	}
	p->pos->y = p->current_tile->pos->y;
	if (render)
		render_up(c);
}

void	down(t_ctx *c, bool render)
{
	t_player	*p;
	t_vector2	*tl;

	p = c->player;
	if (!p->is_awake)
	{
		put_img(c, c->player->sprites->awake);
		p->is_awake = true;
		return ;
	}
	tl = p->current_tile->local_pos;
	p->is_tired = false;
	p->played_anim = false;
	c->world->exit_msg = false;
	c->world->easter_egg = false;
	p->sleep_frames_counter = 0;
	time(&p->last_active_time);
	if (c->world->tiles[tl->y + 1][tl->x].type != WALL)
	{
		p->current_tile = &c->world->tiles[tl->y + 1][tl->x];
		c->player->moves++;
	}
	p->pos->y = p->current_tile->pos->y;
	if (render)
		render_down(c);
}
