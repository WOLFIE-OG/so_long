/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_sleeping_frames.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:32:35 by otodd             #+#    #+#             */
/*   Updated: 2024/03/15 13:11:04 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	lick_frames(t_ctx *c, int offset)
{
	int	i;

	i = 0;
	while (++i <= 7)
	{
		c->player->sleep_frames[offset++] = LICK;
		c->player->sleep_frames[offset++] = IDLE;
	}
	return (offset);
}

static int	scratch_frames(t_ctx *c, int offset)
{
	int	i;

	i = 0;
	while (++i <= 7)
	{
		c->player->sleep_frames[offset++] = SCRATCH;
		c->player->sleep_frames[offset++] = SCRATCH_ALT;
	}
	return (offset);
}

static void	yawn_frames(t_ctx *c, int offset)
{
	int	i;

	i = 0;
	while (++i < 14)
		c->player->sleep_frames[offset++] = YAWN;
}

void	init_frames(t_ctx *c)
{
	int	offset;

	offset = lick_frames(c, 0);
	offset = scratch_frames(c, offset);
	yawn_frames(c, offset);
}
