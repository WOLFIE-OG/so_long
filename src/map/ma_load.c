/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ma_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:06:51 by otodd             #+#    #+#             */
/*   Updated: 2024/02/26 14:19:11 by otodd            ###   ########.fr       */
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

static void	process_lines(int fd, char **m)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		if (ft_strchr(line, '\n'))
			m[i] = ft_strndup(line, ft_strlen(line) - 1);
		else
			m[i] = ft_strdup(line);
		i++;
		free(line);
	}
	m[i] = NULL;
}

char	**load_map(char *path)
{
	int			fd;
	char		**m;
	const int	c = line_count(path);

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	m = malloc(sizeof(char *) * (c + 1));
	if (!m)
	{
		close(fd);
		return (NULL);
	}
	if (c < 3)
	{
		free(m);
		close(fd);
		return (NULL);
	}
	process_lines(fd, m);
	close(fd);
	return (m);
}
