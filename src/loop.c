/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:09:24 by dkaiser           #+#    #+#             */
/*   Updated: 2024/06/10 15:43:17 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loop(void *params)
{
	t_game	*game;

	game = (t_game *)params;
	player_process(game);
	if (game->player.steps)
		ft_printf("\e[1A\e[KSteps: %d\n", game->player.steps);
	draw(game);
}
