/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:04:38 by otodd             #+#    #+#             */
/*   Updated: 2024/02/14 15:02:53 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libs/libft/include/libft.h"
# include "../libs/minilibx/mlx.h"

typedef struct	s_player_sprites
{
	void	*idle;
	void	*up;
	void	*up_alt;
	void	*down;
	void	*down_alt;
	void	*left;
	void	*left_alt;
	void	*right;
	void	*right_alt;
}	t_player_sprites;

typedef struct s_player
{
	t_player_sprites	*sprites;
	int					x;
	int					y;
}	t_player;


typedef struct s_ctx
{
	t_player	*player;
	void		*root;
	void		*mlx_ctx;
}	t_ctx;


#endif