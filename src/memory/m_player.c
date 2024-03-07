/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:28:32 by otodd             #+#    #+#             */
/*   Updated: 2024/03/07 17:26:08 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_player(t_ctx *c)
{
	if (c->player)
	{
		if (c->player->win_pos)
			free(c->player->win_pos);
		free(c->player);
	}
}
