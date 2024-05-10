/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:09:24 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/10 11:17:33 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	loop(void *params)
{
    t_game *game;

    game = (t_game *) params;
	game->player.direction.x = ((game->input_direction & RIGHT) != 0)
		- ((game->input_direction & LEFT) != 0);
	game->player.direction.y = ((game->input_direction & DOWN) != 0)
		- ((game->input_direction & UP) != 0);

    game->player.position.x += game->player.direction.x * PLAYER_MOVE_SPEED;
    game->player.position.y += game->player.direction.y * PLAYER_MOVE_SPEED;

    draw(game);
}
