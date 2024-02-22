/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:04:38 by otodd             #+#    #+#             */
/*   Updated: 2024/02/22 19:48:27 by otodd            ###   ########.fr       */
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
#  define TITLE "Thanks for all the treats"
# endif
# ifndef SIZE
#  define SIZE 32
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
	void	*sleep;
	void	*sleep_alt;
	void	*yawn;
	void	*lick;
	void	*scratch;
	void	*scratch_alt;
	void	*awake;
}	t_player_sprites;

typedef struct s_vector2
{
	int	x;
	int	y;
}	t_vector2;

typedef struct s_world_sprites
{
	void	*wall;
	void	*coin;
	void	*exit;
	void	*spawn;
}	t_world_sprites;

typedef struct s_tile
{
	void		*sprite;
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
	t_player_sprites	**sleep_frames;
	int					sleep_frames_count;
	int					sleep_frames_counter;
}	t_player;

typedef struct s_map
{
	int		rows;
	int		columns;
	int		spawn_count;
	int		exit_count;
	int		coin_count;
	int		wall_count;
	int		empty_count;
	char	**data;
}	t_map;

typedef struct s_world
{
	t_world_sprites	*sprites;
	t_tile			**tiles;
	int				init_x;
	int				init_y;
}	t_world;

typedef struct s_ctx
{
	t_player	*player;
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
	void		*(*n_win)(void *m, int x, int y, char *t);
	int			speed;
	int			max_idle;
}	t_ctx;

void		idle(t_ctx *c);
void		up(t_ctx *c, bool render);
void		down(t_ctx *c, bool render);
void		left(t_ctx *c, bool render);
void		right(t_ctx *c, bool render);
void		up_left(t_ctx *c);
void		up_right(t_ctx *c);
void		down_left(t_ctx *c);
void		down_right(t_ctx *c);
t_ctx		*init_main(char *name);
void		init_player(t_ctx *c);	
void		*lps(t_ctx *c, char *n, int w, int h);
void		*les(t_ctx *c, char *n, int w, int h);
int			check_border(t_ctx *c);
void		free_sprites(t_ctx *c);
void		free_sprites_extra(t_ctx *c);
void		free_sprites_extra_extra(t_ctx *c);
void		free_world_sprites(t_ctx *c);
int			key_check(int key);
int			key_press_handler(int key, t_ctx *c);
int			key_release_handler(int key, t_ctx *c);
int			update(t_ctx *c);
void		free_player(t_ctx *c);
int			close_program(t_ctx *c);
char		**load_map(char *path);
void		parse_map(t_ctx *c);
void		init_world(t_ctx *c);
void		free_world(t_ctx *c);
void		free_tiles(t_ctx *c);
void		destroy(t_ctx *c, char *message, bool is_error);
void		check_sprites(t_ctx *c);
void		check_sprites_extra(t_ctx *c);
void		check_sprites_extra_extra(t_ctx *c);
void		check_world_sprites(t_ctx *c);
t_vector2	*init_vector2(void);
void		free_map(t_ctx *c);
void		init_map(t_ctx *c, char *name);
int			get_height(t_ctx *c);
int			get_width(t_ctx *c);
void		draw_world(t_ctx *c);
int			check_map(t_ctx *c);
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
void		put_img(t_ctx *c, void *img);
void		init_array(t_ctx *c);
void		idle_check(t_ctx *c);
void		tile_detect(t_ctx *c);
void		init_frames(t_ctx *c);

#endif