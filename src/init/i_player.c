/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:01 by otodd             #+#    #+#             */
/*   Updated: 2024/02/19 21:47:24 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	sprites(t_ctx *c, int w, int h)
{
	t_player_sprites	*s;
	s = malloc(sizeof(t_player_sprites));
	c->player->sprites = s;
	if (!s)
		destroy(c, "Failed to alloc player sprites!", 1);
	s->down_alt = lps(c, "down_alt.xpm", w, h);
	s->down = lps(c, "down.xpm", w, h);
	s->idle = lps(c, "idle.xpm", w, h);
	s->left_alt = lps(c, "left_alt.xpm", w, h);
	s->left = lps(c, "left.xpm", w, h);
	s->right_alt = lps(c, "right_alt.xpm", w, h);
	s->right = lps(c, "right.xpm", w, h);
	s->up_alt = lps(c, "up_alt.xpm", w, h);
	s->up = lps(c, "up.xpm", w, h);
}

static void	sprites_extra(t_ctx *c, int w, int h)
{
	t_player_sprites	*s;

	s = c->player->sprites;
	s->down_left_alt = lps(c, "down_left_alt.xpm", w, h);
	s->down_left = lps(c, "down_left.xpm", w, h);
	s->up_left_alt = lps(c, "up_left_alt.xpm", w, h);
	s->up_left = lps(c, "up_left.xpm", w, h);
	s->down_right_alt = lps(c, "down_right_alt.xpm", w, h);
	s->down_right = lps(c, "down_right.xpm", w, h);
	s->up_right_alt = lps(c, "up_right_alt.xpm", w, h);
	s->up_right = lps(c, "up_right.xpm", w, h);
}

static void	sprites_extra_extra(t_ctx *c, int w, int h)
{
	t_player_sprites	*s;

	s = c->player->sprites;
	s->bottom = lps(c, "bottom.xpm", w, h);
	s->bottom_alt = lps(c, "bottom_alt.xpm", w, h);
	s->side_l = lps(c, "side_l.xpm", w, h);
	s->side_l_alt = lps(c, "side_l_alt.xpm", w, h);
	s->side_r = lps(c, "side_r.xpm", w, h);
	s->side_r_alt = lps(c, "side_r_alt.xpm", w, h);
	s->top = lps(c, "top.xpm", w, h);
	s->top_alt = lps(c, "top_alt.xpm", w, h);
}

static void	player(t_ctx *c)
{
	t_player			*player;

	player = (t_player *)malloc(sizeof(t_player));
	c->player = player;
	if (!player)
		destroy(c, "Failed to alloc player!", 1);
	player->pos = (t_vector2 *)malloc(sizeof(t_vector2));
	if (!player->pos)
		destroy(c, "Failed to alloc vector2", 1);
	player->pos->x = 0;
	player->pos->y = 0;
	player->direction = '0';
	player->is_alt = 0;
	ft_printf("["BBLU"DEBUG"RESET"]		Created player\n");
}

void	init_player(t_ctx *ctx)
{
	const int	w = 32;
	const int	h = 32;

	player(ctx);
	sprites(ctx, w, h);
	check_sprites(ctx);
	sprites_extra(ctx, w, h);
	check_sprites_extra(ctx);
	sprites_extra_extra(ctx, w, h);
	check_sprites_extra_extra(ctx);
}
