/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_player_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:44:15 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 22:37:20 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	render_up_left(t_ctx *c)
{
	if (c->player->frame)
		put_img(c, c->player->sprites->up_left_alt);
	else
		put_img(c, c->player->sprites->up_left);
}

void	render_up_right(t_ctx *c)
{
	if (c->player->frame)
		put_img(c, c->player->sprites->up_right_alt);
	else
		put_img(c, c->player->sprites->up_right);
}

void	render_down_left(t_ctx *c)
{
	if (c->player->frame)
		put_img(c, c->player->sprites->down_left_alt);
	else
		put_img(c, c->player->sprites->down_left);
}

void	render_down_right(t_ctx *c)
{
	if (c->player->frame)
		put_img(c, c->player->sprites->down_right_alt);
	else
		put_img(c, c->player->sprites->down_right);
}
