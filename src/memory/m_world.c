/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_world.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:28:32 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 15:27:44 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_world(t_ctx *ctx)
{
	if (ctx->world)
	{
		if (ctx->world->sprites)
		{
			free_world_sprites(ctx);
			free(ctx->world->sprites);
		}
		if (ctx->world->tiles)
			free_tiles(ctx);
		free(ctx->world);
	}
}
