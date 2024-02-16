/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:04:38 by otodd             #+#    #+#             */
/*   Updated: 2024/02/16 15:08:28 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libs/libft/include/libft.h"
# include "../libs/minilibx/mlx.h"
# include "../libs/minilibx/mlx_int.h"
# include <stdbool.h>
# ifndef TITLE
#  define TITLE "Thanks for all the treats"
# endif
# ifndef WIDTH
#  define WIDTH 500
# endif
# ifndef HEIGHT
#  define HEIGHT 500
# endif
# ifndef SPEED
#  define SPEED 10
# endif

enum e_key_binds
{
	KEY_UP = 119,
	KEY_DOWN = 115,
	KEY_LEFT = 97,
	KEY_RIGHT = 100,
	ESC = 65307
};

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
	char				direction;
	int					is_alt;
}	t_player;


typedef struct s_ctx
{
	t_player	*player;
	void		*root;
	int			width;
	int			height;
	void		*mlx_ctx;
	int			game_running;
	int			(*put_i)(void *m, void *w, void *i, int x, int y);
	int			(*des_i)(void *m, void *i);
}	t_ctx;

// Movement

void	idle(t_ctx *ctx);
void	up(t_ctx *ctx);
void	down(t_ctx *ctx);
void	left(t_ctx *ctx);
void	right(t_ctx *ctx);

// Init

t_ctx	*init_main(void);
void	init_player(t_ctx *ctx);
#endif