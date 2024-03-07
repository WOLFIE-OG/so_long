/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_img_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:03:06 by otodd             #+#    #+#             */
/*   Updated: 2024/03/07 17:13:09 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_img	*lps(t_ctx *c, const char *n, int w, int h)
{
	void	*i;
	char	*p;
	char	*p1;
	char	*p2;

	p = ft_strjoin("./res/tex/plr/", c->variant_name);
	p1 = ft_strjoin(p, "/");
	p2 = ft_strjoin(p1, n);
	i = mlx_xpm_file_to_image(c->mlx_ctx, p2, &w, &h);
	if (!i)
	{
		ft_printf("["BRED"DEBUG"RESET"]		Not Loaded: %s\n", n);
		free(p);
		free(p1);
		free(p2);
		return (NULL);
	}
	ft_printf("["BBLU"IMGLDR"RESET"]	Loaded: %s\n", n);
	free(p);
	free(p1);
	free(p2);
	return (i);
}

t_img	*lws(t_ctx *c, const char *n, int w, int h)
{
	void	*i;
	char	*p;

	p = ft_strjoin("./res/tex/wrld/", n);
	i = mlx_xpm_file_to_image(c->mlx_ctx, p, &w, &h);
	if (!i)
	{
		ft_printf("["BRED"DEBUG"RESET"]		Not Loaded: %s\n", n);
		free(p);
		return (NULL);
	}
	ft_printf("["BBLU"IMGLDR"RESET"]	Loaded: %s\n", n);
	free(p);
	return (i);
}
