/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_tiles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:14:11 by otodd             #+#    #+#             */
/*   Updated: 2024/03/07 16:58:29 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	exit_check(t_ctx *c)
{
	if (c->player->coins_collected == c->map->coin_count)
		close_program(c);
	else
	{
		if (!c->world->exit_msg)
		{
			ft_printf("["BRED"INFO"RESET"]		");
			ft_printf("You haven't collected all the coins!\n");
			c->world->exit_msg = true;
		}
	}
}

static void	enemy_check(t_ctx *c)
{
	ft_printf("["BRED"INFO"RESET"]		");
	ft_printf("You hit an enemy!\n");
	close_program(c);
}

void	tile_check(t_ctx *c)
{
	if (c->player->current_tile->type == T_FAKE && !c->world->easter_egg)
	{
		c->world->easter_egg = true;
		ft_printf("["BMAG"????"RESET"]		OMG Developer easter egg??\n");
	}
	if (c->player->current_tile->type == T_COLLECT)
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
	else if (c->player->current_tile->type == T_EXIT)
		exit_check(c);
	else if (c->player->current_tile->type == T_ENEMY)
		enemy_check(c);
}
