/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:28:32 by otodd             #+#    #+#             */
/*   Updated: 2024/02/22 14:07:41 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_player(t_ctx *c)
{
	if (c->player)
	{
		if (c->player->sprites)
		{
			free_sprites(c);
			free_sprites_extra(c);
			free_sprites_extra_extra(c);
			free(c->player->sprites);
		}
		if (c->player->pos)
			free(c->player->pos);
		if (c->player->sleep_frames)
			free(c->player->sleep_frames);
		free(c->player);
	}
}
