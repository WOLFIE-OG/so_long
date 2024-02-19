/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:04:38 by otodd             #+#    #+#             */
/*   Updated: 2024/02/19 12:14:19 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libs/libft/include/libft.h"
# include "../libs/minilibx/mlx.h"
# include "../libs/minilibx/mlx_int.h"
# include <stdbool.h>
# include <math.h>
# ifndef TITLE
#  define TITLE "Thanks for all the treats"
# endif
# ifndef WIDTH
#  define WIDTH 1280
# endif
# ifndef HEIGHT
#  define HEIGHT 720
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

typedef struct s_player_sprites
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
	void	*up_left;
	void	*up_left_alt;
	void	*down_left;
	void	*down_left_alt;
	void	*up_right;
	void	*up_right_alt;
	void	*down_right;
	void	*down_right_alt;
	void	*bottom;
	void	*bottom_alt;
	void	*side_l;
	void	*side_l_alt;
	void	*side_r;
	void	*side_r_alt;
	void	*top;
	void	*top_alt;
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
	int			current_key;
	int			(*put_i)(void *m, void *w, void *i, int x, int y);
	int			(*des_i)(void *m, void *i);
	int		speed;
}	t_ctx;

// Movement

void	idle(t_ctx *c);
void	up(t_ctx *c);
void	down(t_ctx *c);
void	left(t_ctx *c);
void	right(t_ctx *c);
void	up_left(t_ctx *c);
void	up_right(t_ctx *c);
void	down_left(t_ctx *c);
void	down_right(t_ctx *c);

// Init

t_ctx	*init_main(void);
void	init_player(t_ctx *ctx);

// Helpers

void	*lps(t_ctx *c, char *n, int w, int h);
int		check_border(t_ctx *ctx);

void	free_sprites(t_ctx *ctx);
void	free_sprites_extra(t_ctx *ctx);
void	free_sprites_extra_extra(t_ctx *ctx);

int		xp(t_ctx *c);
int		yp(t_ctx *c);

int		key_check(int key);

#endif