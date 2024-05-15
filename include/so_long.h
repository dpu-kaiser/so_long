/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:14:02 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/15 12:06:35 by dkaiser          ###   ########.fr       */
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

typedef struct s_player
{
	t_vector	position;
	t_vector	direction;
	t_vector	velocity;
	t_ivector	size;
	mlx_image_t	*img;
}				t_player;

typedef struct s_tilemap
{
	t_ivector	grid_size;
	t_ivector	tile_size;
	char		*tiles;
	t_ivector	player_start_tile;
	t_ivector	exit_tile;
}				t_tilemap;

typedef struct s_game
{
	mlx_t		*mlx;
	void		*window;
	t_player	player;
	int			input_direction;
	t_tilemap	map;
}				t_game;

int				load_map_from_file(t_tilemap *tilemap, char *filename);

int				init(t_game *game);
void			loop(void *params);
void			player_process(t_game *game);
int				draw(t_game *game);
int				draw_map(t_game *game);
void			on_key_input(mlx_key_data_t event, void *params);
t_vector		grid_to_screen_pos(t_ivector grid_pos, t_ivector tile_size);
t_ivector		screen_to_grid_pos(t_vector screen_pos, t_ivector tile_size);
enum e_tile		get_tile(t_tilemap *map, int x, int y);
int				check_collision(t_vector a_pos, t_ivector a_size,
					t_vector b_pos, t_ivector b_size);
int				check_wall_collision(t_vector a_pos, t_ivector a_size,
					t_tilemap *map);
void			move_and_slide(t_player *player, t_tilemap *map);

#endif // SO_LONG_H
