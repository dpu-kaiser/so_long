/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:14:02 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/29 15:57:34 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include "fcntl.h"
# include "libft.h"
# include "unistd.h"

# define PLAYER_MOVE_SPEED 250

enum			e_tile
{
	EMPTY = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	PLAYER_START = 'P'
};

enum			e_direction
{
	ZERO = 0,
	UP = 1,
	DOWN = 2,
	LEFT = 4,
	RIGHT = 8
};

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_ivector
{
	int			x;
	int			y;
}				t_ivector;

typedef struct s_collider
{
	t_vector	position;
	t_ivector	size;
}				t_collider;

typedef struct s_actor
{
	t_vector	position;
	t_vector	direction;
	t_vector	velocity;
	t_ivector	size;
	mlx_image_t	*img;
}				t_actor;

typedef struct s_tilemap
{
	t_ivector	grid_size;
	t_ivector	tile_size;
	char  *tiles;
	t_ivector	player_start_tile;
	t_ivector	exit_tile;
	mlx_image_t	*collectible_img;
}				t_tilemap;

typedef struct s_game
{
	mlx_t		*mlx;
	void		*window;
	t_actor		player;
	int			input_direction;
	t_tilemap	map;
}				t_game;

int				load_map_from_file(t_tilemap *tilemap, char *filename);
int				check_map(t_tilemap *map);
int check_for_valid_path(t_tilemap *map);

int				init(t_game *game);
void			loop(void *params);
void			player_process(t_game *game);
int				draw(t_game *game);
int				draw_walls(t_game *game);
void			draw_exit(t_game *game);
void			on_key_input(mlx_key_data_t event, void *params);
t_vector		grid_to_screen_pos(t_ivector grid_pos, t_ivector tile_size);
t_ivector		screen_to_grid_pos(t_vector screen_pos, t_ivector tile_size);
enum e_tile		get_tile(t_tilemap *map, int x, int y);
void			set_tile(t_tilemap *map, int x, int y, enum e_tile type);
int				check_collision(t_collider a, t_collider b);
int				check_map_collision(t_collider collider, t_tilemap *map,
					enum e_tile type);
void			move_and_slide(t_actor *actor, t_tilemap *map,
					double delta_time);
int				is_on_floor(t_collider collider, t_tilemap *map);

#endif // SO_LONG_H
