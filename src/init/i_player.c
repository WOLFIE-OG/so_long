/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:01 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 15:37:31 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	sprites(t_ctx *c, int w, int h)
{
	c->player->sprites = malloc(sizeof(t_player_sprites));
	if (!c->player->sprites)
		destroy(c, "Failed to alloc player sprites!", 1);
	c->player->sprites->down_alt = lps(c, "down_alt.xpm", w, h);
	c->player->sprites->down = lps(c, "down.xpm", w, h);
	c->player->sprites->idle = lps(c, "idle.xpm", w, h);
	c->player->sprites->left_alt = lps(c, "left_alt.xpm", w, h);
	c->player->sprites->left = lps(c, "left.xpm", w, h);
	c->player->sprites->right_alt = lps(c, "right_alt.xpm", w, h);
	c->player->sprites->right = lps(c, "right.xpm", w, h);
	c->player->sprites->up_alt = lps(c, "up_alt.xpm", w, h);
	c->player->sprites->up = lps(c, "up.xpm", w, h);
}

static void	sprites_extra(t_ctx *c, int w, int h)
{
	c->player->sprites->down_left_alt = lps(c, "down_left_alt.xpm", w, h);
	c->player->sprites->down_left = lps(c, "down_left.xpm", w, h);
	c->player->sprites->up_left_alt = lps(c, "up_left_alt.xpm", w, h);
	c->player->sprites->up_left = lps(c, "up_left.xpm", w, h);
	c->player->sprites->down_right_alt = lps(c, "down_right_alt.xpm", w, h);
	c->player->sprites->down_right = lps(c, "down_right.xpm", w, h);
	c->player->sprites->up_right_alt = lps(c, "up_right_alt.xpm", w, h);
	c->player->sprites->up_right = lps(c, "up_right.xpm", w, h);
}

static void	sprites_extra_extra(t_ctx *c, int w, int h)
{
	c->player->sprites->bottom = lps(c, "bottom.xpm", w, h);
	c->player->sprites->bottom_alt = lps(c, "bottom_alt.xpm", w, h);
	c->player->sprites->side_l = lps(c, "side_l.xpm", w, h);
	c->player->sprites->side_l_alt = lps(c, "side_l_alt.xpm", w, h);
	c->player->sprites->side_r = lps(c, "side_r.xpm", w, h);
	c->player->sprites->side_r_alt = lps(c, "side_r_alt.xpm", w, h);
	c->player->sprites->top = lps(c, "top.xpm", w, h);
	c->player->sprites->top_alt = lps(c, "top_alt.xpm", w, h);
}

static void	player(t_ctx *c)
{
	c->player = malloc(sizeof(t_player));
	if (!c->player)
		destroy(c, "Failed to alloc player!", 1);
	c->player->pos = init_vector2();
	if (!c->player->pos)
		destroy(c, "Failed to alloc vector2", 1);
	c->player->direction = '0';
	c->player->frame = 0;
	c->player->current_tile = NULL;
	ft_printf("["BBLU"DEBUG"RESET"]		Created player\n");
}

void	init_player(t_ctx *ctx)
{
	const int	w = SIZE;
	const int	h = SIZE;

	player(ctx);
	sprites(ctx, w, h);
	check_sprites(ctx);
	sprites_extra(ctx, w, h);
	check_sprites_extra(ctx);
	sprites_extra_extra(ctx, w, h);
	check_sprites_extra_extra(ctx);
}
