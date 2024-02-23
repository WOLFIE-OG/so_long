/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:44:15 by otodd             #+#    #+#             */
/*   Updated: 2024/02/23 13:59:33 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	render_idle(t_ctx *c)
{
	if (!c->player->is_tired)
		put_img(c, c->player->sprites->idle);
	else
	{
		if (!c->player->played_anim)
		{
			if (c->player->sleep_frames_counter
				!= c->player->sleep_frames_count)
				put_img(c, c->player->sleep_frames[
					c->player->sleep_frames_counter++]);
			else
			{
				c->player->played_anim = true;
				c->player->is_awake = false;
			}
		}
		if (c->player->played_anim)
		{
			if (c->player->frame)
				put_img(c, c->player->sprites->sleep_alt);
			else
				put_img(c, c->player->sprites->sleep);
			usleep(50000);
		}
	}
}

void	render_right(t_ctx *c)
{
	if (!check_border(c))
	{
		if (c->player->frame)
			put_img(c, c->player->sprites->right_alt);
		else
			put_img(c, c->player->sprites->right);
	}
}

void	render_left(t_ctx *c)
{
	if (!check_border(c))
	{
		if (c->player->frame)
			put_img(c, c->player->sprites->left_alt);
		else
			put_img(c, c->player->sprites->left);
	}
}

void	render_up(t_ctx *c)
{
	if (!check_border(c))
	{
		if (c->player->frame)
			put_img(c, c->player->sprites->up_alt);
		else
			put_img(c, c->player->sprites->up);
	}
}

void	render_down(t_ctx *c)
{
	if (!check_border(c))
	{
		if (c->player->frame)
			put_img(c, c->player->sprites->down_alt);
		else
			put_img(c, c->player->sprites->down);
	}
}
