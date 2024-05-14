/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:40:05 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/14 15:12:28 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "so_long.h"

static t_vector	get_direction_from_input(t_game *game);

void	player_process(t_game *game)
{
	t_player	*player;
	t_vector collision_pos;
    int collision;

	player = &game->player;
	player->direction = get_direction_from_input(game);
	player->velocity.x = player->direction.x * PLAYER_MOVE_SPEED
		* game->mlx->delta_time;
	player->velocity.y = player->direction.y * PLAYER_MOVE_SPEED
		* game->mlx->delta_time;

	collision_pos.x = player->position.x + player->velocity.x;
	collision_pos.y = player->position.y + player->velocity.y;
    collision = check_wall_collision(collision_pos, game->map.tile_size, &game->map);
	if (collision & LEFT && player->velocity.x < 0)
		player->velocity.x = 0;
	if (collision & RIGHT && player->velocity.x > 0)
		player->velocity.x = 0;
	if (collision & UP && player->velocity.y < 0)
		player->velocity.y = 0;
	if (collision & DOWN && player->velocity.y > 0)
		player->velocity.y = 0;

	player->position.x += player->velocity.x;
	player->position.y += player->velocity.y;
}

static t_vector	get_direction_from_input(t_game *game)
{
	t_vector	result;

	result.x = ((game->input_direction & RIGHT) != 0)
		- ((game->input_direction & LEFT) != 0);
	result.y = ((game->input_direction & DOWN) != 0)
		- ((game->input_direction & UP) != 0);
	return (result);
}
