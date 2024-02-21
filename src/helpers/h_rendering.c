/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_rendering.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:52:59 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 20:56:30 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	put_img(t_ctx *c, void *img)
{
	c->put_i(
		c->mlx_ctx,
		c->root, img,
		c->player->pos->x,
		c->player->pos->y
	);
}
