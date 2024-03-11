/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ho_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:30:35 by otodd             #+#    #+#             */
/*   Updated: 2024/03/11 16:36:07 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	alt_shift(t_ctx *c)
{
	if (c->player->frame)
		c->player->frame = 0;
	else
		c->player->frame = 1;
}

static void	move(t_ctx *c)
{
	if (c->player->direction == M_UP)
		up(c, true);
	else if (c->player->direction == M_LEFT)
		left(c, true);
	else if (c->player->direction == M_DOWN)
		down(c, true);
	else if (c->player->direction == M_RIGHT)
		right(c, true);
	else if (c->player->direction == M_UP_LEFT)
		up_left(c);
	else if (c->player->direction == M_UP_RIGHT)
		up_right(c);
	else if (c->player->direction == M_DOWN_LEFT)
		down_left(c);
	else if (c->player->direction == M_DOWN_RIGHT)
		down_right(c);
	else
		idle(c);
}

// static char	**dup_map(t_ctx *c)
// {
// 	int			i;
// 	char		**dup;
// 
// 	i = 0;
// 	dup = malloc(sizeof(char *) * (c->map->columns + 1 * c->map->rows + 1));
// 	dup[0] = ft_strjoin(" ", ft_strdup(c->map->data[i]));
// 	while (++i < c->map->columns + 1)
// 		dup[0][i] = ' ';
// 	i = 0;
// 	while (i < c->map->rows)
// 	{
// 		dup[i + 1] = ft_strjoin(" ", ft_strdup(c->map->data[i]));
// 		i++;
// 	}
// 	dup[i + 1] = NULL;
// 	return (dup);
// }
// static void	debug(t_ctx *c)
// {
// 	int		i;
// 	size_t 	k;
// 	char	**tmp;
// 
// 	i = -1;
// 	ft_printf(CLEAR_ALL);
// 	ft_printf("X: %d Y: %d\n", c->player->current_tile->map_pos->x,
// 			c->player->current_tile->map_pos->y);
// 	ft_printf("\v\v ");
// 	while (++i < c->map->rows + 1)
// 	{
// 		tmp = dup_map(c);
// 		tmp[c->player->current_tile->map_pos->y + 1]
// 			[c->player->current_tile->map_pos->x + 1] = 'X';
// 		tmp[c->player->current_tile->map_pos->y + 1][0] = 'H';
// 		tmp[0][c->player->current_tile->map_pos->x+ 1] = 'W';
// 		k = 0;
// 		ft_printf("\t ");
// 		while (k < ft_strlen(tmp[i]))
// 		{
// 			if (tmp[i][k] == 'X')
// 				ft_printf(BBLU"%c"RESET, tmp[i][k]);
// 			else if (tmp[i][k] == 'N')
// 				ft_printf(BRED"%c"RESET, tmp[i][k]);
// 			else if (tmp[i][k] == 'C')
// 				ft_printf(BGRN"%c"RESET, tmp[i][k]);
// 			else if (tmp[i][k] == 'P')
// 				ft_printf(BYEL"%c"RESET, tmp[i][k]);
// 			else if (tmp[i][k] == 'E')
// 				ft_printf(BCYN"%c"RESET, tmp[i][k]);
// 			else
// 				ft_printf("%c", tmp[i][k]);
// 			k++;
// 			ft_printf(" ");
// 		}
// 		ft_printf("\n");
// 		free(tmp);
// 	}
// }

int	update(t_ctx *c)
{
	if (!c->game_running)
		return (0);
	mlx_clear_window(c->mlx_ctx, c->root);
	ft_bzero(c->buffer->data, c->buffer->size_line * c->height);
	calculate_world(c);
	move(c);
	alt_shift(c);
	tile_check(c);
	idle_check(c);
	mlx_put_image_to_window(c->mlx_ctx, c->root, c->buffer, 0, 0);
	moves_text(c);
	enemys_text(c);
	coins_text(c);
	usleep(166667);
	return (0);
}
