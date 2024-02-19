/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ma_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:06:51 by otodd             #+#    #+#             */
/*   Updated: 2024/02/19 20:18:05 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	line_count(char *path)
{
	int		fd;
	int		line_c;
	int		bytes;
	char	c;

	bytes = 1;
	c = 0;
	fd = open(path, O_RDONLY);
	line_c = 1;
	while (bytes)
	{
		bytes = read(fd, &c, 1);
		if (!bytes)
			break ;
		if (bytes < 0)
			break ;
		if (c == '\n')
			line_c++;
	}
	close(fd);
	return (line_c);
}

char	**load_map(char *path)
{
	int		fd;
	char	*line;
	char	**m;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	m = malloc(sizeof(char *) * (line_count(path) + 1));
	i = 0;
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		m[i] = ft_strdup(line);
		i++;
		free(line);
	}
	m[i] = NULL;
	close(fd);
	return (m);
}
