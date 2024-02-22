/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_sprites.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:53:45 by otodd             #+#    #+#             */
/*   Updated: 2024/02/22 11:20:09 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_sprites(t_ctx *c)
{
	if (c->player->sprites->down_alt)
		c->des_i(c->mlx_ctx, c->player->sprites->down_alt);
	if (c->player->sprites->down)
		c->des_i(c->mlx_ctx, c->player->sprites->down);
	if (c->player->sprites->idle)
		c->des_i(c->mlx_ctx, c->player->sprites->idle);
	if (c->player->sprites->left_alt)
		c->des_i(c->mlx_ctx, c->player->sprites->left_alt);
	if (c->player->sprites->left)
		c->des_i(c->mlx_ctx, c->player->sprites->left);
	if (c->player->sprites->right_alt)
		c->des_i(c->mlx_ctx, c->player->sprites->right_alt);
	if (c->player->sprites->right)
		c->des_i(c->mlx_ctx, c->player->sprites->right);
	if (c->player->sprites->up_alt)
		c->des_i(c->mlx_ctx, c->player->sprites->up_alt);
	if (c->player->sprites->up)
		c->des_i(c->mlx_ctx, c->player->sprites->up);
	if (c->player->sprites->sleept_alt)
		c->des_i(c->mlx_ctx, c->player->sprites->sleept_alt);
	if (c->player->sprites->sleep)
		c->des_i(c->mlx_ctx, c->player->sprites->sleep);
}

void	free_sprites_extra(t_ctx *c)
{
	if (c->player->sprites->down_left_alt)
		c->des_i(c->mlx_ctx, c->player->sprites->down_left_alt);
	if (c->player->sprites->down_left)
		c->des_i(c->mlx_ctx, c->player->sprites->down_left);
	if (c->player->sprites->down_right_alt)
		c->des_i(c->mlx_ctx, c->player->sprites->down_right_alt);
	if (c->player->sprites->down_right)
		c->des_i(c->mlx_ctx, c->player->sprites->down_right);
	if (c->player->sprites->up_left_alt)
		c->des_i(c->mlx_ctx, c->player->sprites->up_left_alt);
	if (c->player->sprites->up_left)
		c->des_i(c->mlx_ctx, c->player->sprites->up_left);
	if (c->player->sprites->up_right_alt)
		c->des_i(c->mlx_ctx, c->player->sprites->up_right_alt);
	if (c->player->sprites->up_right)
		c->des_i(c->mlx_ctx, c->player->sprites->up_right);
}

void	free_sprites_extra_extra(t_ctx *c)
{
	if (c->player->sprites->bottom_alt)
		c->des_i(c->mlx_ctx, c->player->sprites->bottom_alt);
	if (c->player->sprites->bottom)
		c->des_i(c->mlx_ctx, c->player->sprites->bottom);
	if (c->player->sprites->top_alt)
		c->des_i(c->mlx_ctx, c->player->sprites->top_alt);
	if (c->player->sprites->top)
		c->des_i(c->mlx_ctx, c->player->sprites->top);
	if (c->player->sprites->side_l_alt)
		c->des_i(c->mlx_ctx, c->player->sprites->side_l_alt);
	if (c->player->sprites->side_l)
		c->des_i(c->mlx_ctx, c->player->sprites->side_l);
	if (c->player->sprites->side_r_alt)
		c->des_i(c->mlx_ctx, c->player->sprites->side_r_alt);
	if (c->player->sprites->side_r)
		c->des_i(c->mlx_ctx, c->player->sprites->side_r);
}

void	free_world_sprites(t_ctx *c)
{
	if (c->world->sprites->wall)
		c->des_i(c->mlx_ctx, c->world->sprites->wall);
	if (c->world->sprites->coin)
		c->des_i(c->mlx_ctx, c->world->sprites->coin);
	if (c->world->sprites->exit)
		c->des_i(c->mlx_ctx, c->world->sprites->exit);
	if (c->world->sprites->spawn)
		c->des_i(c->mlx_ctx, c->world->sprites->spawn);
}
