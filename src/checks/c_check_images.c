/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_check_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:18:23 by otodd             #+#    #+#             */
/*   Updated: 2024/02/22 14:10:04 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_sprites(t_ctx *c)
{
	if (c && c->player && c->player->sprites)
	{
		if (!c->player->sprites->down_alt)
			destroy(c, "down_alt.xpm not found!", 1);
		if (!c->player->sprites->down)
			destroy(c, "down.xpm not found!", 1);
		if (!c->player->sprites->idle)
			destroy(c, "idle.xpm not found!", 1);
		if (!c->player->sprites->left_alt)
			destroy(c, "left_alt.xpm not found!", 1);
		if (!c->player->sprites->left)
			destroy(c, "left.xpm not found!", 1);
		if (!c->player->sprites->right_alt)
			destroy(c, "right_alt.xpm not found!", 1);
		if (!c->player->sprites->right)
			destroy(c, "right.xpm not found!", 1);
		if (!c->player->sprites->up_alt)
			destroy(c, "up_alt.xpm not found!", 1);
		if (!c->player->sprites->up)
			destroy(c, "up.xpm not found!", 1);
		if (!c->player->sprites->sleep_alt)
			destroy(c, "sleep_alt.xpm not found!", 1);
		if (!c->player->sprites->sleep)
			destroy(c, "sleep.xpm not found!", 1);
	}
}

void	check_sprites_extra(t_ctx *c)
{
	if (c && c->player && c->player->sprites)
	{
		if (!c->player->sprites->down_left_alt)
			destroy(c, "down_left_alt.xpm not found!", 1);
		if (!c->player->sprites->down_left)
			destroy(c, "down_left.xpm not found!", 1);
		if (!c->player->sprites->down_right_alt)
			destroy(c, "down_right_alt.xpm not found!", 1);
		if (!c->player->sprites->down_right)
			destroy(c, "down_right.xpm not found!", 1);
		if (!c->player->sprites->up_left_alt)
			destroy(c, "up_left_alt.xpm not found!", 1);
		if (!c->player->sprites->up_left)
			destroy(c, "up_left.xpm not found!", 1);
		if (!c->player->sprites->up_right_alt)
			destroy(c, "up_right_alt.xpm not found!", 1);
		if (!c->player->sprites->up_right)
			destroy(c, "up_right.xpm not found!", 1);
		if (!c->player->sprites->yawn)
			destroy(c, "yawn.xpm not found!", 1);
		if (!c->player->sprites->lick)
			destroy(c, "lick.xpm not found!", 1);
		if (!c->player->sprites->awake)
			destroy(c, "awake.xpm not found!", 1);
	}
}

void	check_sprites_extra_extra(t_ctx *c)
{
	if (c && c->player && c->player->sprites)
	{
		if (!c->player->sprites->bottom_alt)
			destroy(c, "bottom_alt.xpm not found!", 1);
		if (!c->player->sprites->bottom)
			destroy(c, "bottom.xpm not found!", 1);
		if (!c->player->sprites->top_alt)
			destroy(c, "top_alt.xpm not found!", 1);
		if (!c->player->sprites->top)
			destroy(c, "top.xpm not found!", 1);
		if (!c->player->sprites->side_l_alt)
			destroy(c, "side_l_alt.xpm not found!", 1);
		if (!c->player->sprites->side_l)
			destroy(c, "side_l.xpm not found!", 1);
		if (!c->player->sprites->side_r_alt)
			destroy(c, "side_r_alt.xpm not found!", 1);
		if (!c->player->sprites->side_r)
			destroy(c, "side_r.xpm not found!", 1);
		if (!c->player->sprites->scratch_alt)
			destroy(c, "scratch_alt.xpm not found!", 1);
		if (!c->player->sprites->scratch)
			destroy(c, "scratch.xpm not found!", 1);
	}
}

void	check_world_sprites(t_ctx *c)
{
	if (c && c->world && c->world->sprites)
	{
		if (!c->world->sprites->wall)
			destroy(c, "wall.xpm not found!", 1);
		if (!c->world->sprites->coin)
			destroy(c, "coin.xpm not found!", 1);
		if (!c->world->sprites->exit)
			destroy(c, "exit.xpm not found!", 1);
		if (!c->world->sprites->spawn)
			destroy(c, "spawn.xpm not found!", 1);
	}
}
