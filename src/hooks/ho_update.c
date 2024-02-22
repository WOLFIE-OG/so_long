/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ho_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:30:35 by otodd             #+#    #+#             */
/*   Updated: 2024/02/22 11:20:47 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	ui_text(t_ctx *c)
{
	char	*a;
	char	*b;

	a = ft_itoa(c->player->moves);
	b = ft_strjoin("Moves: ", a);
	free(a);
	mlx_string_put(
		c->mlx_ctx,
		c->root,
		(c->width / 2) - SIZE,
		(c->height + SIZE / 2) - 5,
		0xFFFFFF,
		b
		);
	free(b);
}

static void	alt_shift(t_ctx *c)
{
	if (c->player->frame)
		c->player->frame = 0;
	else
		c->player->frame = 1;
}

static void	tile_detect(t_ctx *c)
{
	if (c->player->current_tile->type == COLLECT)
	{
		if (!c->player->current_tile->hidden)
		{
			c->player->coins_collected++;
			c->player->current_tile->hidden = 1;
			ft_printf("["BGRN"INFO"RESET"]		You have collected [%d / %d]\n",
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

static void	extended(t_ctx *c)
{
	alt_shift(c);
	tile_detect(c);
	idle_check(c);
	ui_text(c);
}

int	update(t_ctx *c)
{
	if (!c->game_running)
		return (0);
	mlx_clear_window(c->mlx_ctx, c->root);
	draw_world(c);
	if (c->player->direction == UP)
		up(c);
	else if (c->player->direction == LEFT)
		left(c);
	else if (c->player->direction == DOWN)
		down(c);
	else if (c->player->direction == RIGHT)
		right(c);
	else if (c->player->direction == UP_LEFT)
		up_left(c);
	else if (c->player->direction == UP_RIGHT)
		up_right(c);
	else if (c->player->direction == DOWN_LEFT)
		down_left(c);
	else if (c->player->direction == DOWN_RIGHT)
		down_right(c);
	else
		idle(c);
	extended(c);
	usleep(166667);
	return (0);
}
