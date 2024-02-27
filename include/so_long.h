/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:04:38 by otodd             #+#    #+#             */
/*   Updated: 2024/02/27 16:22:22 by otodd            ###   ########.fr       */
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
	UP = 'W',
	LEFT = 'A',
	DOWN = 'S',
	RIGHT = 'D',
	IDLE = '0',
	UP_LEFT = '1',
	UP_RIGHT = '2',
	DOWN_LEFT = '3',
	DOWN_RIGHT = '4'
};

enum e_tiles
{
	EMPTY = '0',
	WALL = '1',
	COLLECT = 'C',
	EXIT = 'E',
	SPAWN = 'P',
	FAKE = 'F',
	ENEMY = 'N'
};

typedef struct s_player_sprites
{
	t_img	*idle;
	t_img	*up;
	t_img	*up_alt;
	t_img	*down;
	t_img	*down_alt;
	t_img	*left;
	t_img	*left_alt;
	t_img	*right;
	t_img	*right_alt;
	t_img	*up_left;
	t_img	*up_left_alt;
	t_img	*down_left;
	t_img	*down_left_alt;
	t_img	*up_right;
	t_img	*up_right_alt;
	t_img	*down_right;
	t_img	*down_right_alt;
	t_img	*bottom;
	t_img	*bottom_alt;
	t_img	*side_l;
	t_img	*side_l_alt;
	t_img	*side_r;
	t_img	*side_r_alt;
	t_img	*top;
	t_img	*top_alt;
	t_img	*sleep;
	t_img	*sleep_alt;
	t_img	*yawn;
	t_img	*lick;
	t_img	*scratch;
	t_img	*scratch_alt;
	t_img	*awake;
}	t_player_sprites;

typedef struct s_vector2
{
	int	x;
	int	y;
}	t_vector2;

typedef struct s_world_sprites
{
	t_img	*wall;
	t_img	*coin;
	t_img	*coin_alt;
	t_img	*exit;
	t_img	*spawn;
	t_img	*enemy;
	t_img	*enemy_alt;
}	t_world_sprites;

typedef struct s_tile
{
	t_img		*sprite;
	t_img		*sprite_alt;
	int			type;
	int			hidden;
	t_vector2	*pos;
	t_vector2	*local_pos;
}	t_tile;

typedef struct s_player
{
	t_player_sprites	*sprites;
	t_vector2			*pos;
	char				direction;
	int					frame;
	t_tile				*current_tile;
	int					moves;
	int					coins_collected;
	time_t				last_active_time;
	bool				is_tired;
	bool				is_awake;
	bool				played_anim;
	t_img				**sleep_frames;
	int					sleep_frames_count;
	int					sleep_frames_counter;
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
	t_world_sprites	*sprites;
	t_tile			**tiles;
	int				init_x;
	int				init_y;
	bool			easter_egg;
	bool			exit_msg;
}	t_world;

typedef struct s_ctx
{
	t_player	*player;
	t_world		*world;
	t_map		*map;
	char		*win_title;
	t_win_list	*root;
	int			width;
	int			height;
	t_xvar		*mlx_ctx;
	int			game_running;
	int			current_key;
	int			(*des_i)(void *m, void *i);
	int			speed;
	int			max_idle;
	t_img		*buffer;
}	t_ctx;

// Checks

int			check_border(t_ctx *c);
void		check_sprites(t_ctx *c);
void		check_sprites_extra(t_ctx *c);
void		check_sprites_extra_extra(t_ctx *c);
void		check_world_sprites(t_ctx *c);
int			check_paths(t_ctx *c);
void		idle_check(t_ctx *c);
void		tile_check(t_ctx *c);
int			check_map(t_ctx *c);
int			key_check(int key);

// Helpers

int			get_height(t_ctx *c);
int			get_width(t_ctx *c);
void		*lps(t_ctx *c, char *n, int w, int h);
void		*les(t_ctx *c, char *n, int w, int h);

// Hooks

int			close_program(t_ctx *c);
int			key_press_handler(int key, t_ctx *c);
int			key_release_handler(int key, t_ctx *c);
int			update(t_ctx *c);

// Init

t_ctx		*init_main(char *name);
void		init_player(t_ctx *c);
t_vector2	*init_vector2(void);
void		init_frames(t_ctx *c);
void		init_mlx(t_ctx *c, char *name);
void		init_world(t_ctx *c);
void		init_world(t_ctx *c);
void		init_map(t_ctx *c, char *name);
void		init_ui(t_ctx *c);

// Map

char		**load_map(char *path);
void		parse_map(t_ctx *c);

// Memory

void		free_sprites(t_ctx *c);
void		free_sprites_extra(t_ctx *c);
void		free_sprites_extra_extra(t_ctx *c);
void		free_world_sprites(t_ctx *c);
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

void		draw_world(t_ctx *c);
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