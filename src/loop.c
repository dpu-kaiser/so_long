/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:09:24 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/14 12:45:26 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loop(void *params)
{
	t_game	*game;

	game = (t_game *)params;
	player_process(game);
	draw(game);
}
