/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_tiles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:14:11 by otodd             #+#    #+#             */
/*   Updated: 2024/02/26 13:39:56 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	tile_detect(t_ctx *c)
{
	if (c->player->current_tile->type == FAKE && !c->world->easter_egg)
	{
		c->world->easter_egg = true;
		ft_printf("["BMAG"????"RESET"]		OMG Developer easter egg??\n");
	}
	if (c->player->current_tile->type == COLLECT)
	{
		if (!c->player->current_tile->hidden)
		{
			c->player->coins_collected++;
			c->player->current_tile->hidden = 1;
			ft_printf("["BGRN"INFO"RESET"]		Coins collected [%d / %d]\n",
				c->player->coins_collected, c->map->coin_count);
			if (c->player->coins_collected == c->map->coin_count)
			{
				ft_printf("["BBLU"INFO"RESET"]		");
				ft_printf("You have collected all the coins!\n");
			}
		}
	}
	else if (c->player->current_tile->type == EXIT)
		close_program(c);
}
