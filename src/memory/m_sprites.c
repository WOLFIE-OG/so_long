/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_sprites.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:53:45 by otodd             #+#    #+#             */
/*   Updated: 2024/03/08 19:24:15 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_sprites(t_ctx *c)
{
	int			i;

	i = 0;
	while (i < NUM_SPRITES)
	{
		if (c->sprites[c->sprite_table[i].sprite])
			c->des_i(c->mlx_ctx, c->sprites[c->sprite_table[i].sprite]);
		i++;
	}
}