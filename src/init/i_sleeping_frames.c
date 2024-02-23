/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_sleeping_frames.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:32:35 by otodd             #+#    #+#             */
/*   Updated: 2024/02/23 14:23:36 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_frames(t_ctx *c)
{
	c->player->sleep_frames = malloc(c->player->sleep_frames_count
			* sizeof(t_img *));
	if (!c->player->sleep_frames)
		destroy(c, "Failed to alloc frames!", 1);
	c->player->sleep_frames[0] = c->player->sprites->lick;
	c->player->sleep_frames[1] = c->player->sprites->idle;
	c->player->sleep_frames[2] = c->player->sprites->lick;
	c->player->sleep_frames[3] = c->player->sprites->idle;
	c->player->sleep_frames[4] = c->player->sprites->lick;
	c->player->sleep_frames[5] = c->player->sprites->idle;
	c->player->sleep_frames[6] = c->player->sprites->lick;
	c->player->sleep_frames[7] = c->player->sprites->idle;
	c->player->sleep_frames[8] = c->player->sprites->scratch;
	c->player->sleep_frames[9] = c->player->sprites->scratch_alt;
	c->player->sleep_frames[10] = c->player->sprites->scratch;
	c->player->sleep_frames[11] = c->player->sprites->scratch_alt;
	c->player->sleep_frames[12] = c->player->sprites->scratch;
	c->player->sleep_frames[13] = c->player->sprites->scratch_alt;
	c->player->sleep_frames[14] = c->player->sprites->scratch;
	c->player->sleep_frames[15] = c->player->sprites->scratch_alt;
	c->player->sleep_frames[16] = c->player->sprites->yawn;
	c->player->sleep_frames[17] = c->player->sprites->yawn;
	c->player->sleep_frames[18] = c->player->sprites->yawn;
	c->player->sleep_frames[19] = c->player->sprites->yawn;
	c->player->sleep_frames[20] = c->player->sprites->yawn;
}
