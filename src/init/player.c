/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:22:01 by otodd             #+#    #+#             */
/*   Updated: 2024/02/17 23:27:17 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	sprites(t_ctx *ctx)
{
	t_player_sprites	*s;
	int					w;
	int					h;
	char				*dir;

	dir = "./res/tex/plr/";
	w = 30;
	h = 30;
	s = (t_player_sprites *)malloc(sizeof(t_player_sprites));
	if (!s)
		exit(1);
	s->down_alt = lps(ctx, ft_strjoin(dir, "down_alt.xpm"), w, h);
	s->down = lps(ctx, ft_strjoin(dir, "down.xpm"), w, h);
	s->idle = lps(ctx, ft_strjoin(dir, "idle.xpm"), w, h);
	s->left_alt = lps(ctx, ft_strjoin(dir, "left_alt.xpm"), w, h);
	s->left = lps(ctx, ft_strjoin(dir, "left.xpm"), w, h);
	s->right_alt = lps(ctx, ft_strjoin(dir, "right_alt.xpm"), w, h);
	s->right = lps(ctx, ft_strjoin(dir, "right.xpm"), w, h);
	s->up_alt = lps(ctx, ft_strjoin(dir, "up_alt.xpm"), w, h);
	s->up = lps(ctx, ft_strjoin(dir, "up.xpm"), w, h);
	ctx->player->sprites = s;
}

static void	sprites_extra(t_ctx *ctx)
{
	t_player_sprites	*s;
	int					w;
	int					h;
	char				*dir;

	s = ctx->player->sprites;
	dir = "./res/tex/plr/";
	w = 30;
	h = 30;
	s->down_left_alt = lps(ctx, ft_strjoin(dir, "down_left_alt.xpm"), w, h);
	s->down_left = lps(ctx, ft_strjoin(dir, "down_left.xpm"), w, h);
	s->up_left_alt = lps(ctx, ft_strjoin(dir, "up_left_alt.xpm"), w, h);
	s->up_left = lps(ctx, ft_strjoin(dir, "up_left.xpm"), w, h);
	s->down_right_alt = lps(ctx, ft_strjoin(dir, "down_right_alt.xpm"), w, h);
	s->down_right = lps(ctx, ft_strjoin(dir, "down_right.xpm"), w, h);
	s->up_right_alt = lps(ctx, ft_strjoin(dir, "up_right_alt.xpm"), w, h);
	s->up_right = lps(ctx, ft_strjoin(dir, "up_right.xpm"), w, h);
}

static void	sprites_extra_extra(t_ctx *ctx)
{
	t_player_sprites	*s;
	int					w;
	int					h;
	char				*dir;

	s = ctx->player->sprites;
	dir = "./res/tex/plr/";
	w = 30;
	h = 30;
	s->bottom = lps(ctx, ft_strjoin(dir, "bottom.xpm"), w, h);
	s->bottom_alt = lps(ctx, ft_strjoin(dir, "bottom_alt.xpm"), w, h);
	s->side_l = lps(ctx, ft_strjoin(dir, "side_l.xpm"), w, h);
	s->side_l_alt = lps(ctx, ft_strjoin(dir, "side_l_alt.xpm"), w, h);
	s->side_r = lps(ctx, ft_strjoin(dir, "side_r.xpm"), w, h);
	s->side_r_alt = lps(ctx, ft_strjoin(dir, "side_r_alt.xpm"), w, h);
	s->top = lps(ctx, ft_strjoin(dir, "top.xpm"), w, h);
	s->top_alt = lps(ctx, ft_strjoin(dir, "top_alt.xpm"), w, h);
}

static void	player(t_ctx *ctx)
{
	t_player			*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		exit(1);
	player->x = (WIDTH / 2);
	player->y = (HEIGHT / 2);
	player->direction = '0';
	player->is_alt = 0;
	ctx->player = player;
	ft_printf("Created player\n");
}

void	init_player(t_ctx *ctx)
{
	player(ctx);
	sprites(ctx);
	sprites_extra(ctx);
	sprites_extra_extra(ctx);
}
