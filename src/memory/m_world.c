/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_world.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:28:32 by otodd             #+#    #+#             */
/*   Updated: 2024/03/07 16:53:54 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_world(t_ctx *c)
{
	if (c->world)
	{
		if (c->world->tiles)
			free_tiles(c);
		free(c->world);
	}
}
