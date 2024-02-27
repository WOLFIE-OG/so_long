/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:06:07 by otodd             #+#    #+#             */
/*   Updated: 2024/02/27 14:03:07 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	check_char(t_ctx *c, char t)
{
	if (t == COLLECT)
		c->map->coin_count++;
	else if (t == WALL)
		c->map->wall_count++;
	else if (t == ENEMY)
		c->map->enemy_count++;
	else if (t == SPAWN)
		c->map->spawn_count++;
	else if (t == EXIT)
		c->map->exit_count++;
	else if (t == FAKE)
		return ;
	else if (t == EMPTY)
		return ;
	else
		c->map->invalid_count++;
	return ;
}

static int	check_width(t_ctx *c)
{
	int	i;

	i = 0;
	while (c->map->data[i])
		if (((int)ft_strlen(c->map->data[i++])) != c->map->columns)
			return (0);
	return (1);
}

static int	check_borders(t_ctx *c)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < c->map->columns)
	{
		if (c->map->data[0][i] != WALL ||
			c->map->data[c->map->rows - 1][i] != WALL)
			return (0);
		++i;
	}
	while (j < c->map->rows - 1)
	{
		if (c->map->data[j][0] != WALL ||
			c->map->data[j][c->map->columns - 1] != WALL)
			return (0);
		++j;
	}
	return (1);
}

static void	count_chars(t_ctx *c)
{
	int	i;
	int	j;

	i = 0;
	while (i < c->map->rows)
	{
		j = 0;
		while (j < c->map->columns)
		{
			check_char(c, c->map->data[i][j]);
			++j;
		}
		++i;
	}
}

int	check_map(t_ctx *c)
{
	if (!check_width(c))
		return (0);
	if (!check_borders(c))
		return (0);
	count_chars(c);
	if (c->map->coin_count < 1)
		return (0);
	else if (c->map->exit_count != 1)
		return (0);
	else if (c->map->spawn_count != 1)
		return (0);
	else if (c->map->invalid_count > 0)
		return (0);
	if (!check_paths(c))
		return (0);
	return (1);
}
