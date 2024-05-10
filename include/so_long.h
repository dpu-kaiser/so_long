/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:14:02 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/10 10:55:30 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PLAYER_MOVE_SPEED 3

# include "libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

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
	int			x;
	int			y;
}				t_vector;

typedef struct s_player
{
	t_vector	position;
	t_vector    direction;
	t_vector	velocity;
	void *img;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_player	player;
	int			input_direction;
}				t_game;

int				init(t_game *game);
int				loop(t_game *game);
int				draw(t_game *game);
int				on_key_down(int key, t_game *game);
int				on_key_up(int keycode, t_game *game);

#endif // SO_LONG_H
