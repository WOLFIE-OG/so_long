/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_borders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:55:38 by otodd             #+#    #+#             */
/*   Updated: 2024/03/08 19:44:13 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	render_border_top(t_ctx *c)
{
	if (c->player->frame)
		put_img(c, c->sprites[TOP_ALT]);
	else
		put_img(c, c->sprites[TOP]);
}

void	render_border_bottom(t_ctx *c)
{
	if (c->player->frame)
		put_img(c, c->sprites[BOTTOM_ALT]);
	else
		put_img(c, c->sprites[BOTTOM]);
}

void	render_border_side_l(t_ctx *c)
{
	if (c->player->frame)
		put_img(c, c->sprites[SIDE_L_ALT]);
	else
		put_img(c, c->sprites[SIDE_L]);
}

void	render_border_side_r(t_ctx *c)
{
	if (c->player->frame)
		put_img(c, c->sprites[SIDE_R_ALT]);
	else
		put_img(c, c->sprites[SIDE_R]);
}
