/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:00:36 by otodd             #+#    #+#             */
/*   Updated: 2024/02/27 11:09:04 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static char	*path(t_ctx *c, char *name)
{
	char	*tmp;

	tmp = ft_strjoin("./res/maps/", name);
	if (!tmp)
	{
		free(tmp);
		destroy(c, "Failed to join str!", 1);
	}
	return (tmp);
}

void	init_map(t_ctx *c, char *name)
{
	char	*tmp;

	tmp = path(c, name);
	c->map = malloc(sizeof(t_map));
	if (!c->map)
		destroy(c, "Failed to alloc map!", 1);
	c->map->coin_count = 0;
	c->map->exit_count = 0;
	c->map->spawn_count = 0;
	c->map->enemy_count = 0;
	c->map->invalid_count = 0;
	c->map->data = load_map(tmp);
	if (!c->map->data)
	{
		free(tmp);
		destroy(c, "Failed to load map!", 1);
	}
	free(tmp);
	c->map->rows = get_height(c);
	c->map->columns = get_width(c);
	if (!check_map(c))
		destroy(c, "Map is invalid!", 1);
	ft_printf("["BBLU"MAP"RESET"]		Created map\n");
}
