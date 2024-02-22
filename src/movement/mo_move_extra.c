/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mo_move_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:12:29 by otodd             #+#    #+#             */
/*   Updated: 2024/02/22 17:31:55 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	up_left(t_ctx *c)
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
	p->sleep_frames_counter = 0;
	time(&p->last_active_time);
	if (c->world->tiles[tl->y - 1][tl->x - 1].type != WALL)
	{
		p->current_tile = &c->world->tiles[tl->y - 1][tl->x - 1];
		c->player->moves++;
	}
	p->pos->x = p->current_tile->pos->x;
	p->pos->y = p->current_tile->pos->y;
	render_up_left(c);
}

void	up_right(t_ctx *c)
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
	p->sleep_frames_counter = 0;
	time(&p->last_active_time);
	if (c->world->tiles[tl->y - 1][tl->x + 1].type != WALL)
	{
		p->current_tile = &c->world->tiles[tl->y - 1][tl->x + 1];
		c->player->moves++;
	}
	p->pos->x = p->current_tile->pos->x;
	p->pos->y = p->current_tile->pos->y;
	render_up_right(c);
}

void	down_left(t_ctx *c)
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
	p->sleep_frames_counter = 0;
	time(&p->last_active_time);
	if (c->world->tiles[tl->y + 1][tl->x - 1].type != WALL)
	{
		p->current_tile = &c->world->tiles[tl->y + 1][tl->x - 1];
		c->player->moves++;
	}
	p->pos->x = p->current_tile->pos->x;
	p->pos->y = p->current_tile->pos->y;
	render_down_left(c);
}

void	down_right(t_ctx *c)
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
	p->sleep_frames_counter = 0;
	time(&p->last_active_time);
	if (c->world->tiles[tl->y + 1][tl->x + 1].type != WALL)
	{
		p->current_tile = &c->world->tiles[tl->y + 1][tl->x + 1];
		c->player->moves++;
	}
	p->pos->x = p->current_tile->pos->x;
	p->pos->y = p->current_tile->pos->y;
	render_down_right(c);
}
