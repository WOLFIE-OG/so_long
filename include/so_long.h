/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:04:38 by otodd             #+#    #+#             */
/*   Updated: 2024/02/20 17:44:03 by otodd            ###   ########.fr       */
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
# ifndef SPEED
#  define SPEED 32
# endif

enum e_key_binds
{
	KEY_UP = 119,
	KEY_DOWN = 115,
	KEY_LEFT = 97,
	KEY_RIGHT = 100,
	ESC = 65307
};

enum e_tiles
{
	WALL = '1',
	COLLECT = 'C',
	EXIT = 'E',
	SPAWN = 'P'	
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

typedef struct s_vector2
{
	int	x;
	int	y;
} t_vector2;


typedef	struct s_world_sprites
{
	void	*wall;
}	t_world_sprites;

typedef struct s_tile
{
	void		*sprite;
	int			type;
	bool		hidden;
	t_vector2	*pos;
	
}	t_tile;

typedef struct s_player
{
	t_player_sprites	*sprites;
	t_vector2			*pos;
	char				direction;
	int					is_alt;
}	t_player;

typedef struct s_map
{
	int		rows;
	int		columns;
	char	**data;
} t_map;

typedef	struct s_world
{
	t_world_sprites	*sprites;
	t_tile			**tiles;
	int				init_l;
	int				init_k;
}	t_world;


typedef struct s_ctx
{
	t_player	*player;
	t_vector2	*start_pos;
	t_world		*world;
	t_map		*map;
	void		*root;
	int			width;
	int			height;
	void		*mlx_ctx;
	int			game_running;
	int			current_key;
	int			(*put_i)(void *m, void *w, void *i, int x, int y);
	int			(*des_i)(void *m, void *i);
	int			speed;
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
void	*les(t_ctx *c, char *n, int w, int h);
int		check_border(t_ctx *ctx);

void	free_sprites(t_ctx *ctx);
void	free_sprites_extra(t_ctx *ctx);
void	free_sprites_extra_extra(t_ctx *ctx);
void	free_world_sprites(t_ctx *ctx);

int		xp(t_ctx *c);
int		yp(t_ctx *c);

int		key_check(int key);

int		key_press_handler(int key, t_ctx *ctx);
int		key_release_handler(int key, t_ctx *ctx);

int		update(t_ctx *ctx);

void	free_player(t_ctx *ctx);

int		close_program(t_ctx *ctx);

char	**load_map(char *path);
void	parse_map(t_ctx *ctx);

void	init_world(t_ctx *ctx);

void	free_world(t_ctx *ctx);

void	destroy(t_ctx *ctx, char *message, int type);

void	check_sprites(t_ctx *ctx);
void	check_sprites_extra(t_ctx *ctx);
void	check_sprites_extra_extra(t_ctx *ctx);
void	check_world_sprites(t_ctx *ctx);

#endif