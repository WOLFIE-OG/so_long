/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_player_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:44:15 by otodd             #+#    #+#             */
/*   Updated: 2024/03/07 17:16:08 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	render_up_left(t_ctx *c)
{
	if (c->player->frame)
		put_img(c, c->sprites[UP_LEFT_ALT]);
	else
		put_img(c, c->sprites[UP_LEFT]);
}

void	render_up_right(t_ctx *c)
{
	if (c->player->frame)
		put_img(c, c->sprites[UP_RIGHT_ALT]);
	else
		put_img(c, c->sprites[UP_RIGHT]);
}

void	render_down_left(t_ctx *c)
{
	if (c->player->frame)
		put_img(c, c->sprites[DOWN_LEFT_ALT]);
	else
		put_img(c, c->sprites[DOWN_LEFT]);
}

void	render_down_right(t_ctx *c)
{
	if (c->player->frame)
		put_img(c, c->sprites[DOWN_RIGHT_ALT]);
	else
		put_img(c, c->sprites[DOWN_RIGHT]);
}
