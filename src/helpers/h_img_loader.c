/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_img_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:03:06 by otodd             #+#    #+#             */
/*   Updated: 2024/02/19 21:42:34 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	*lps(t_ctx *c, char *n, int w, int h)
{
	void	*i;
	char	*p;

	p = ft_strjoin("./res/tex/plr/", n);
	i = mlx_xpm_file_to_image(c->mlx_ctx, p, &w, &h);
	if (!i)
	{
		ft_printf("["BRED"DEBUG"RESET"]	Not Loaded: %s\n", n);
		free(p);
		return (NULL);
	}
	ft_printf("["BBLU"IMGLDR"RESET"]	Loaded: %s\n", n);
	free(p);
	return (i);
}

void	*les(t_ctx *c, char *n, int w, int h)
{
	void	*i;
	char	*p;

	p = ft_strjoin("./res/tex/wrld/", n);
	i = mlx_xpm_file_to_image(c->mlx_ctx, p, &w, &h);
	if (!i)
	{
		ft_printf("["BRED"DEBUG"RESET"]	Not Loaded: %s\n", n);
		free(p);
		return (NULL);
	}
	ft_printf("["BBLU"IMGLDR"RESET"]	Loaded: %s\n", n);
	free(p);
	return (i);
}
