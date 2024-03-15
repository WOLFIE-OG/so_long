/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:04:38 by otodd             #+#    #+#             */
/*   Updated: 2024/03/15 12:48:26 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libs/libft/include/libft.h"
# include "../libs/minilibx/mlx.h"
# include "../libs/minilibx/mlx_int.h"
# include <time.h>
# include <stdbool.h>
# ifndef TITLE
#  define TITLE "Thanks for all the treats :3 | "
# endif
# ifndef SIZE
#  define SIZE 32
# endif
# ifndef MAX_IDLE
#  define MAX_IDLE 3
# endif

enum e_key_binds
{
	KEY_UP = 119,
	KEY_DOWN = 115,
	KEY_LEFT = 97,
	KEY_RIGHT = 100,
	ESC = 65307
};

enum e_direction
{
	M_UP = 'W',
	M_LEFT = 'A',
	M_DOWN = 'S',
	M_RIGHT = 'D',
	M_IDLE = '0',
	M_UP_LEFT = '1',
	M_UP_RIGHT = '2',
	M_DOWN_LEFT = '3',
	M_DOWN_RIGHT = '4'
};

enum e_tiles
{
	T_EMPTY = '0',
	T_WALL = '1',
	T_COLLECT = 'C',
	T_EXIT = 'E',
	T_SPAWN = 'P',
	T_ENEMY = 'N'
};

enum e_variant
{
	CAT = 0,
	TABBY_CAT = 1,
	DOG = 2,
	DEVIL = 3,
	CAT_GIRL = 4
};

enum e_sprites
{
	IDLE,
	UP,
	UP_ALT,
	DOWN,
	DOWN_ALT,
	LEFT,
	LEFT_ALT,
	RIGHT,
	RIGHT_ALT,
	UP_LEFT,
	UP_LEFT_ALT,
	DOWN_LEFT,
	DOWN_LEFT_ALT,
	UP_RIGHT,
	UP_RIGHT_ALT,
	DOWN_RIGHT,
	DOWN_RIGHT_ALT,
	TOP,
	TOP_ALT,
	BOTTOM,
	BOTTOM_ALT,
	SIDE_L,
	SIDE_L_ALT,
	SIDE_R,
	SIDE_R_ALT,
	SLEEP,
	SLEEP_ALT,
	YAWN,
	LICK,
	SCRATCH,
	SCRATCH_ALT,
	AWAKE,
	WALL,
	COIN,
	COIN_ALT,
	EXIT,
	SPAWN,
	ENEMY,
	ENEMY_ALT,
	NUM_SPRITES
};

typedef struct s_sprite_item
{
	enum e_sprites	sprite;
	char			*file_name;
}	t_sprite_item;

typedef struct s_tile
{
	t_img		*sprite;
	t_img		*sprite_alt;
	int			type;
	int			hidden;
	t_vector2	*win_pos;
	t_vector2	*map_pos;
}	t_tile;

typedef struct s_player
{
	t_vector2		*win_pos;
	char			direction;
	int				frame;
	t_tile			*current_tile;
	int				moves;
	int				coins_collected;
	time_t			last_active_time;
	bool			is_tired;
	bool			is_awake;
	bool			played_anim;
	enum e_sprites	sleep_frames[41];
	int				sleep_frames_counter;
}	t_player;

typedef struct s_map
{
	int		rows;
	int		columns;
	int		spawn_count;
	int		enemy_count;
	int		exit_count;
	int		coin_count;
	int		wall_count;
	int		invalid_count;
	char	**data;
}	t_map;

typedef struct s_world
{
	t_tile	**tiles;
	int		init_x;
	int		init_y;
	bool	exit_msg;
}	t_world;

typedef struct s_ctx
{
	t_img			**sprites;
	t_player		*player;
	t_world			*world;
	t_map			*map;
	char			*win_title;
	t_win_list		*root;
	int				width;
	int				height;
	t_xvar			*mlx_ctx;
	int				game_running;
	int				current_key;
	int				(*des_i)(void *m, void *i);
	int				speed;
	int				max_idle;
	t_img			*buffer;
	int				variant;
	char			*variant_name;
	t_sprite_item	sprite_table[NUM_SPRITES];
}	t_ctx;

// Checks

int			check_border(t_ctx *c);
void		check_sprites(t_ctx *c);
int			check_paths(t_ctx *c);
void		idle_check(t_ctx *c);
void		tile_check(t_ctx *c);
int			check_map(t_ctx *c);
int			key_check(int key);

// Helpers

int			get_height(t_ctx *c);
int			get_width(t_ctx *c);
t_img		*lps(t_ctx *c, const char *n, int w, int h);
t_img		*lws(t_ctx *c, const char *n, int w, int h);
void		set_variant_name(t_ctx *c);

// Hooks

int			close_program(t_ctx *c);
int			key_press_handler(int key, t_ctx *c);
int			key_release_handler(int key, t_ctx *c);
int			update(t_ctx *c);

// Init

t_ctx		*init_main(char *name, int variant);
void		init_player(t_ctx *c);
void		init_frames(t_ctx *c);
void		init_mlx(t_ctx *c, char *name);
void		init_world(t_ctx *c);
void		init_sprite_table(t_ctx *c);
void		init_map(t_ctx *c, char *name);
void		init_ui(t_ctx *c);

// Map

char		**load_map(char *path);
void		parse_map(t_ctx *c);

// Memory

void		free_sprites(t_ctx *c);
void		free_player(t_ctx *c);
void		free_world(t_ctx *c);
void		free_tiles(t_ctx *c);
void		destroy(t_ctx *c, char *message, bool is_error);
void		free_map(t_ctx *c);
void		put_buf(t_ctx *c, t_img *img, int x, int y);
void		put_img(t_ctx *c, t_img *img);

// Movement

void		idle(t_ctx *c);
void		up(t_ctx *c, bool render);
void		down(t_ctx *c, bool render);
void		left(t_ctx *c, bool render);
void		right(t_ctx *c, bool render);
void		up_left(t_ctx *c);
void		up_right(t_ctx *c);
void		down_left(t_ctx *c);
void		down_right(t_ctx *c);

// Rendering

void		calculate_world(t_ctx *c);
void		render_border_top(t_ctx *c);
void		render_border_bottom(t_ctx *c);
void		render_border_side_l(t_ctx *c);
void		render_border_side_r(t_ctx *c);
void		render_up(t_ctx *c);
void		render_down(t_ctx *c);
void		render_left(t_ctx *c);
void		render_right(t_ctx *c);
void		render_idle(t_ctx *c);
void		render_up_left(t_ctx *c);
void		render_up_right(t_ctx *c);
void		render_down_left(t_ctx *c);
void		render_down_right(t_ctx *c);
void		moves_text(t_ctx *c);
void		enemys_text(t_ctx *c);
void		coins_text(t_ctx *c);

#endif