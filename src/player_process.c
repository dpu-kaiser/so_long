/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:40:05 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/15 13:53:01 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "so_long.h"

static t_vector	get_direction_from_input(t_game *game);

void	player_process(t_game *game)
{
	t_player	*player;

	player = &game->player;
	player->direction = get_direction_from_input(game);
	player->velocity.x = player->direction.x * PLAYER_MOVE_SPEED;
	player->velocity.y += 50;
	if (player->direction.y == -1 && is_on_floor(player->position, player->size,
			&game->map))
		player->velocity.y = -1000;
	move_and_slide(player, &game->map, game->mlx->delta_time);
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
