/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_sleeping_frames.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:32:35 by otodd             #+#    #+#             */
/*   Updated: 2024/03/08 18:49:03 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	lick_frames(t_ctx *c, int offset)
{
	int	i;

	i = 0;
	while (i <= 4)
	{
		c->player->sleep_frames[offset] = LICK;
		offset++;
		c->player->sleep_frames[offset] = IDLE;
		offset++;
		i++;
	}
}

static void	scratch_frames(t_ctx *c, int offset)
{
	int	i;

	i = 0;
	while (i <= 4)
	{
		c->player->sleep_frames[offset] = SCRATCH;
		offset++;
		c->player->sleep_frames[offset] = SCRATCH_ALT;
		offset++;
		i++;
	}
}


static void	yawn_frames(t_ctx *c, int offset)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		c->player->sleep_frames[offset] = YAWN;
		offset++;
		i++;
	}
}

void	init_frames(t_ctx *c)
{
	int	offset;

	offset = 0;
	lick_frames(c, offset);
	scratch_frames(c, offset);
	yawn_frames(c, offset);
}
