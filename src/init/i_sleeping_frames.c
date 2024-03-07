/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_sleeping_frames.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:32:35 by otodd             #+#    #+#             */
/*   Updated: 2024/03/07 16:38:52 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_frames(t_ctx *c)
{
	c->player->sleep_frames[0] = LICK;
	c->player->sleep_frames[1] = IDLE;
	c->player->sleep_frames[2] = LICK;
	c->player->sleep_frames[3] = IDLE;
	c->player->sleep_frames[4] = LICK;
	c->player->sleep_frames[5] = IDLE;
	c->player->sleep_frames[6] = LICK;
	c->player->sleep_frames[7] = IDLE;
	c->player->sleep_frames[8] = SCRATCH;
	c->player->sleep_frames[9] = SCRATCH_ALT;
	c->player->sleep_frames[10] = SCRATCH;
	c->player->sleep_frames[11] = SCRATCH_ALT;
	c->player->sleep_frames[12] = SCRATCH;
	c->player->sleep_frames[13] = SCRATCH_ALT;
	c->player->sleep_frames[14] = SCRATCH;
	c->player->sleep_frames[15] = SCRATCH_ALT;
	c->player->sleep_frames[16] = YAWN;
	c->player->sleep_frames[17] = YAWN;
	c->player->sleep_frames[18] = YAWN;
	c->player->sleep_frames[19] = YAWN;
	c->player->sleep_frames[20] = YAWN;
}
