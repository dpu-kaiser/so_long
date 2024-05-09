/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:37:40 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/09 17:48:20 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_key_down(int keycode, t_game *game)
{
	if (keycode == 13)
		game->input_direction |= UP;
	else if (keycode == 0)
		game->input_direction |= LEFT;
	else if (keycode == 1)
		game->input_direction |= DOWN;
	else if (keycode == 2)
		game->input_direction |= RIGHT;
	return (0);
}

int	on_key_up(int keycode, t_game *game)
{
	if (keycode == 13)
		game->input_direction &= ~UP;
	else if (keycode == 0)
		game->input_direction &= ~LEFT;
	else if (keycode == 1)
		game->input_direction &= ~DOWN;
	else if (keycode == 2)
		game->input_direction &= ~RIGHT;
	return (0);
}
