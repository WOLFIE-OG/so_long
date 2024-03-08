/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_sprite_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:45:34 by otodd             #+#    #+#             */
/*   Updated: 2024/03/08 19:20:17 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	world_sprite_table(t_ctx *c)
{
	c->sprite_table[WALL] = (t_sprite_item){WALL, "wall.xpm"};
	c->sprite_table[COIN] = (t_sprite_item){COIN, "coin.xpm"};
	c->sprite_table[COIN_ALT] = (t_sprite_item){COIN_ALT, "coin_alt.xpm"};
	c->sprite_table[EXIT] = (t_sprite_item){EXIT, "exit.xpm"};
	c->sprite_table[SPAWN] = (t_sprite_item){SPAWN, "spawn.xpm"};
	c->sprite_table[ENEMY] = (t_sprite_item){ENEMY, "enemy.xpm"};
	c->sprite_table[ENEMY_ALT] = (t_sprite_item){ENEMY_ALT, "enemy_alt.xpm"};
}

static void	misc_sprite_table(t_ctx *c)
{
	c->sprite_table[BOTTOM] = (t_sprite_item){BOTTOM, "bottom.xpm"};
	c->sprite_table[BOTTOM_ALT]
		= (t_sprite_item){BOTTOM_ALT, "bottom_alt.xpm"};
	c->sprite_table[SIDE_L] = (t_sprite_item){SIDE_L, "side_l.xpm"};
	c->sprite_table[SIDE_L_ALT] = (t_sprite_item){SIDE_L_ALT, "side_l_alt.xpm"};
	c->sprite_table[SIDE_R] = (t_sprite_item){SIDE_R, "side_r.xpm"};
	c->sprite_table[SIDE_R_ALT] = (t_sprite_item){SIDE_R_ALT, "side_r_alt.xpm"};
	c->sprite_table[TOP] = (t_sprite_item){TOP, "top.xpm"};
	c->sprite_table[TOP_ALT] = (t_sprite_item){TOP_ALT, "top_alt.xpm"};
	c->sprite_table[SLEEP] = (t_sprite_item){SLEEP, "sleep.xpm"};
	c->sprite_table[SLEEP_ALT] = (t_sprite_item){SLEEP_ALT, "sleep_alt.xpm"};
	c->sprite_table[YAWN] = (t_sprite_item){YAWN, "yawn.xpm"};
	c->sprite_table[LICK] = (t_sprite_item){LICK, "lick.xpm"};
	c->sprite_table[SCRATCH] = (t_sprite_item){SCRATCH, "scratch.xpm"};
	c->sprite_table[SCRATCH_ALT]
		= (t_sprite_item){SCRATCH_ALT, "scratch_alt.xpm"};
	c->sprite_table[AWAKE] = (t_sprite_item){AWAKE, "awake.xpm"};
	world_sprite_table(c);
}

static void	second_sprite_table(t_ctx *c)
{
	c->sprite_table[UP_LEFT]
		= (t_sprite_item){UP_LEFT, "up_left.xpm"};
	c->sprite_table[UP_LEFT_ALT]
		= (t_sprite_item){UP_LEFT_ALT, "up_left_alt.xpm"};
	c->sprite_table[DOWN_LEFT]
		= (t_sprite_item){DOWN_LEFT, "down_left.xpm"};
	c->sprite_table[DOWN_LEFT_ALT]
		= (t_sprite_item){DOWN_LEFT_ALT, "down_left_alt.xpm"};
	c->sprite_table[UP_RIGHT]
		= (t_sprite_item){UP_RIGHT, "up_right.xpm"};
	c->sprite_table[UP_RIGHT_ALT]
		= (t_sprite_item){UP_RIGHT_ALT, "up_right_alt.xpm"};
	c->sprite_table[DOWN_RIGHT]
		= (t_sprite_item){DOWN_RIGHT, "down_right.xpm"};
	c->sprite_table[DOWN_RIGHT_ALT]
		= (t_sprite_item){DOWN_RIGHT_ALT, "down_right_alt.xpm"};
	misc_sprite_table(c);
}

void	init_sprite_table(t_ctx *c)
{
	int	i;

	i = 0;
	while (i < NUM_SPRITES)
		c->sprites[i++] = NULL;
	c->sprite_table[IDLE] = (t_sprite_item){IDLE, "idle.xpm"};
	c->sprite_table[UP] = (t_sprite_item){UP, "up.xpm"};
	c->sprite_table[UP_ALT] = (t_sprite_item){UP_ALT, "up_alt.xpm"};
	c->sprite_table[DOWN] = (t_sprite_item){DOWN, "down.xpm"};
	c->sprite_table[DOWN_ALT] = (t_sprite_item){DOWN_ALT, "down_alt.xpm"};
	c->sprite_table[LEFT] = (t_sprite_item){LEFT, "left.xpm"};
	c->sprite_table[LEFT_ALT] = (t_sprite_item){LEFT_ALT, "left_alt.xpm"};
	c->sprite_table[RIGHT] = (t_sprite_item){RIGHT, "right.xpm"};
	c->sprite_table[RIGHT_ALT] = (t_sprite_item){RIGHT_ALT, "right_alt.xpm"};
	second_sprite_table(c);
}