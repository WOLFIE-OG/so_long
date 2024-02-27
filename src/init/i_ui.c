/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_ui.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:25:44 by otodd             #+#    #+#             */
/*   Updated: 2024/02/27 15:13:49 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	compact_ui(t_ctx *c)
{
	put_buf(c,
		c->player->sprites->idle,
		(c->width / 2) - (SIZE * 2),
		(c->height + (SIZE / 2) * 2)
		);
	put_buf(c,
		c->world->sprites->enemy,
		(c->width / 2) - (SIZE * 2),
		(c->height + (SIZE / 2) * 4)
		);
	put_buf(c,
		c->world->sprites->coin,
		(c->width / 2) - (SIZE * 2),
		(c->height + (SIZE / 2) - (SIZE / 2))
		);
}

static void	large_ui(t_ctx *c)
{
	put_buf(c,
		c->player->sprites->idle,
		(((c->width / 2) - SIZE) - (SIZE / 2)),
		(c->height + (SIZE / 2) / 2)
		);
	put_buf(c,
		c->world->sprites->enemy,
		((c->width / 2) + (SIZE * 3)),
		(c->height + (SIZE / 2) / 2)
		);
	put_buf(c,
		c->world->sprites->coin,
		((c->width / 2) - (SIZE * 6)),
		(c->height + (SIZE / 2) / 2)
		);
}

void	init_ui(t_ctx *c)
{
	if (c->width < (SIZE * 15))
		compact_ui(c);
	else
		large_ui(c);
}
