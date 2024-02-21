/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_borders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:55:38 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 18:58:59 by otodd            ###   ########.fr       */
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
		c->put_i(c->mlx_ctx, c->root, s->top_alt, xp(c), yp(c));
	else
		c->put_i(c->mlx_ctx, c->root, s->top, xp(c), yp(c));
}

void	render_border_bottom(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->frame)
		c->put_i(c->mlx_ctx, c->root, s->bottom_alt, xp(c), yp(c));
	else
		c->put_i(c->mlx_ctx, c->root, s->bottom, xp(c), yp(c));
}

void	render_border_side_l(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->frame)
		c->put_i(c->mlx_ctx, c->root, s->side_l_alt, xp(c), yp(c));
	else
		c->put_i(c->mlx_ctx, c->root, s->side_l, xp(c), yp(c));
}

void	render_border_side_r(t_ctx *c)
{
	t_player			*p;
	t_player_sprites	*s;

	p = c->player;
	s = p->sprites;
	if (p->frame)
		c->put_i(c->mlx_ctx, c->root, s->side_r_alt, xp(c), yp(c));
	else
		c->put_i(c->mlx_ctx, c->root, s->side_r, xp(c), yp(c));
}