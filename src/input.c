/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:37:40 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/10 11:33:09 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	on_key_down(mlx_key_data_t keydata, void *params)
{
	t_game *game;
	int keycode;

	keycode = keydata.os_key;

	game = (t_game *) params;

	if (keydata.action == MLX_RELEASE)
	{
		on_key_up(keycode, game);
		return;
	}

	if (keycode == 13 || keycode == 126)
		game->input_direction |= UP;
	else if (keycode == 0 || keycode == 123)
		game->input_direction |= LEFT;
	else if (keycode == 1 || keycode == 125)
		game->input_direction |= DOWN;
	else if (keycode == 2 || keycode == 124)
		game->input_direction |= RIGHT;
}

int	on_key_up(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 126)
		game->input_direction &= ~UP;
	else if (keycode == 0 || keycode == 123)
		game->input_direction &= ~LEFT;
	else if (keycode == 1 || keycode == 125)
		game->input_direction &= ~DOWN;
	else if (keycode == 2 || keycode == 124)
		game->input_direction &= ~RIGHT;
	return (0);
}
