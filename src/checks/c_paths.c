/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_paths.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:33:51 by otodd             #+#    #+#             */
/*   Updated: 2024/03/05 13:23:26 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	fill_paths(char	**data, int i, int j)
{
	if (data[i][j] == '1' || data[i][j] == 'x' || data[i][j] == 'N')
		return ;
	data[i][j] = 'x';
	fill_paths(data, i + 1, j);
	fill_paths(data, i - 1, j);
	fill_paths(data, i, j - 1);
	fill_paths(data, i, j + 1);
}

static t_vector2	*find_pos_char(t_ctx *c, char **data, char to_find)
{
	int			i;
	int			j;
	t_vector2	*pos;

	i = 0;
	pos = NULL;
	while (i < c->map->rows)
	{
		j = 0;
		while (j < c->map->columns)
		{
			if (data[i][j] == to_find)
			{
				pos = malloc(sizeof(t_vector2));
				pos->y = i;
				pos->x = j;
			}
			++j;
		}
		++i;
	}
	return (pos);
}

static char	**dup_map(t_ctx *c)
{
	int			i;
	char		**dup;

	i = 0;
	dup = malloc(sizeof(char *) * (c->map->columns * c->map->rows));
	if (!dup)
		return (NULL);
	while (i < c->map->rows)
	{
		dup[i] = ft_strdup(c->map->data[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

int	check_paths(t_ctx *c)
{
	char		**map_dup;
	t_vector2	*pos;

	map_dup = dup_map(c);
	if (!map_dup)
		destroy(c, "Failed to duplicate map!", 1);
	pos = find_pos_char(c, map_dup, 'P');
	fill_paths(map_dup, pos->y, pos->x);
	free(pos);
	pos = find_pos_char(c, map_dup, 'E');
	if (pos)
	{
		ft_free_array(map_dup, ft_strarraylen(map_dup));
		free(map_dup);
		free(pos);
		return (0);
	}
	ft_free_array(map_dup, ft_strarraylen(map_dup));
	free(map_dup);
	return (1);
}
