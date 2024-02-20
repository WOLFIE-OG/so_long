/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_world.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:28:32 by otodd             #+#    #+#             */
/*   Updated: 2024/02/20 16:50:24 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_world(t_ctx *ctx)
{
	if (ctx && ctx->world)
	{
		if (ctx->world->sprites)
		{
			free_world_sprites(ctx);
			free(ctx->world->sprites);
		}
		free(ctx->world);
	}
}
