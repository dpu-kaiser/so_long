/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:14:02 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/10 14:55:46 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include "unistd.h"
# include "fcntl.h"

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
	mlx_image_t	*img;
}				t_player;

typedef struct s_tilemap
{
	t_ivector	grid_size;
	t_ivector	tile_size;
	char		**tiles;
}				t_tilemap;

typedef struct s_game
{
	mlx_t		*mlx;
	void		*window;
	t_player	player;
	int			input_direction;
}				t_game;

int				init(t_game *game);
void			loop(void *params);
int				draw(t_game *game);
void			on_key_input(mlx_key_data_t event, void *params);

#endif // SO_LONG_H
