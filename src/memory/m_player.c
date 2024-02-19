/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:28:32 by otodd             #+#    #+#             */
/*   Updated: 2024/02/19 21:12:54 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_player(t_ctx *ctx)
{
	if (ctx && ctx->player)
	{
		if (ctx->player->sprites)
		{
			free_sprites(ctx);
			free_sprites_extra(ctx);
			free_sprites_extra_extra(ctx);
			free(ctx->player->sprites);
		}
		if (ctx->player->pos)
			free(ctx->player->pos);
		free(ctx->player);
	}
}
