/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:00:36 by otodd             #+#    #+#             */
/*   Updated: 2024/03/15 13:40:39 by otodd            ###   ########.fr       */
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
		destroy(c, "Failed to join str!", true);
	}
	return (tmp);
}

void	init_map(t_ctx *c, char *name)
{
	char	*tmp;

	tmp = path(c, name);
	if (!ft_isvalid_file_path(tmp))
	{
		free(tmp);
		destroy(c, "Map path not valid!", true);
	}
	c->map = malloc(sizeof(t_map));
	if (!c->map)
		destroy(c, "Failed to alloc map!", true);
	c->map->data = load_map(tmp);
	if (!c->map->data)
	{
		free(tmp);
		destroy(c, "Failed to load map!", true);
	}
	free(tmp);
	c->map->rows = get_height(c);
	c->map->columns = get_width(c);
	if (!check_map(c))
		destroy(c, "Map is invalid!", true);
	ft_printf("["BBLU"MAP"RESET"]		Created map\n");
}
