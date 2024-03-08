/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:01 by otodd             #+#    #+#             */
/*   Updated: 2024/03/08 19:41:34 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	sprites(t_ctx *c)
{
	const int	w = SIZE;
	const int	h = SIZE;
	int			i;

	i = 0;
	while (i < (NUM_SPRITES - 7))
	{
		c->sprites[c->sprite_table[i].sprite]
			= lps(c, c->sprite_table[i].file_name, w, h);
		i++;
	}
}

static void	player(t_ctx *c)
{
	c->player = malloc(sizeof(t_player));
	if (!c->player)
		destroy(c, "Failed to alloc player!", true);
	c->player->win_pos = vector2(0, 0);
	if (!c->player->win_pos)
		destroy(c, "Failed to alloc vector2", true);
	c->player->direction = '0';
	c->player->frame = 0;
	c->player->moves = 0;
	c->player->current_tile = NULL;
	c->player->coins_collected = 0;
	c->player->is_tired = false;
	c->player->played_anim = false;
	c->player->is_awake = true;
	c->player->sleep_frames_count = 41;
	c->player->sleep_frames_counter = 0;
	time(&c->player->last_active_time);
	ft_printf("["BBLU"PLAYER"RESET"]	Created player\n");
}

void	init_player(t_ctx *c)
{
	player(c);
	set_variant_name(c);
	sprites(c);
	init_frames(c);
}
