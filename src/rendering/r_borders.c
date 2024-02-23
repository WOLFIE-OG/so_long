/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_borders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:55:38 by otodd             #+#    #+#             */
/*   Updated: 2024/02/23 13:59:47 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	render_border_top(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->frame)
		put_img(c, s->top_alt);
	else
		put_img(c, s->top);
}

void	render_border_bottom(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->frame)
		put_img(c, s->bottom_alt);
	else
		put_img(c, s->bottom);
}

void	render_border_side_l(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->frame)
		put_img(c, s->side_l_alt);
	else
		put_img(c, s->side_l);
}

void	render_border_side_r(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->frame)
		put_img(c, s->side_r_alt);
	else
		put_img(c, s->side_r);
}
