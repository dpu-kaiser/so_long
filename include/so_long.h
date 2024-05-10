/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:14:02 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/10 12:24:12 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PLAYER_MOVE_SPEED 250
# include "MLX42/MLX42.h"
# include "libft.h"

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

typedef struct s_player
{
	t_vector	position;
	t_vector	direction;
	t_vector	velocity;
	mlx_image_t	*img;
}				t_player;

typedef struct s_game
{
	mlx_t		*mlx;
	void		*window;
	t_player	player;
	int			input_direction;
}				t_game;

int				init(t_game *game);
void			loop(void *game);
int				draw(t_game *game);
void			on_key_input(mlx_key_data_t event, void *params);

#endif // SO_LONG_H
