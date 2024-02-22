/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:44:15 by otodd             #+#    #+#             */
/*   Updated: 2024/02/22 11:21:49 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	render_idle(t_ctx *c)
{
	if (!c->player->is_idle)
		put_img(c, c->player->sprites->idle);
	else
	{
		usleep(500000);
		if (c->player->frame)
			put_img(c, c->player->sprites->sleept_alt);
		else
			put_img(c, c->player->sprites->sleep);
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
