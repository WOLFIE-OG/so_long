/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:03:06 by otodd             #+#    #+#             */
/*   Updated: 2024/02/16 19:03:32 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	*lps(t_ctx *c, char *n, int w, int h)
{
	void	*i;

	i = mlx_xpm_file_to_image(c->mlx_ctx, n, &w, &h);
	if (!i)
		exit(1);
	ft_printf("Loaded: %s\n", n);
	free(n);
	return (i);
}