/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:44:15 by otodd             #+#    #+#             */
/*   Updated: 2024/03/11 19:44:52 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	render_idle(t_ctx *c)
{
	if (!c->player->is_tired)
		put_img(c, c->sprites[IDLE]);
	else
	{
		if (!c->player->played_anim)
		{
			if (c->player->sleep_frames_counter
				!= 41)
				put_img(c, c->sprites[c->player->sleep_frames[
					c->player->sleep_frames_counter++]]);
			else
			{
				c->player->played_anim = true;
				c->player->is_awake = false;
			}
		}
		if (c->player->played_anim)
		{
			if (c->player->frame)
				put_img(c, c->sprites[SLEEP_ALT]);
			else
				put_img(c, c->sprites[SLEEP]);
		}
	}
}

void	render_right(t_ctx *c)
{
	if (!check_border(c))
	{
		if (c->player->frame)
			put_img(c, c->sprites[RIGHT_ALT]);
		else
			put_img(c, c->sprites[RIGHT]);
	}
}

void	render_left(t_ctx *c)
{
	if (!check_border(c))
	{
		if (c->player->frame)
			put_img(c, c->sprites[LEFT_ALT]);
		else
			put_img(c, c->sprites[LEFT]);
	}
}

void	render_up(t_ctx *c)
{
	if (!check_border(c))
	{
		if (c->player->frame)
			put_img(c, c->sprites[UP_ALT]);
		else
			put_img(c, c->sprites[UP]);
	}
}

void	render_down(t_ctx *c)
{
	if (!check_border(c))
	{
		if (c->player->frame)
			put_img(c, c->sprites[DOWN_ALT]);
		else
			put_img(c, c->sprites[DOWN]);
	}
}
