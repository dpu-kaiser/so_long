/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:37:40 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/10 12:11:48 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void on_key_input(mlx_key_data_t event, void *params)
{
	t_game *game;

	game = (t_game *) params;
	if (event.action == MLX_PRESS)
	{
		if (event.key == MLX_KEY_W || event.key == MLX_KEY_UP)
			game->input_direction |= UP;
		else if (event.key == MLX_KEY_A || event.key == MLX_KEY_LEFT)
			game->input_direction |= LEFT;
		else if (event.key == MLX_KEY_S || event.key == MLX_KEY_DOWN)
			game->input_direction |= DOWN;
		else if (event.key == MLX_KEY_D || event.key == MLX_KEY_RIGHT)
			game->input_direction |= RIGHT;
	}
	else if (event.action == MLX_RELEASE)
	{
		if (event.key == MLX_KEY_W || event.key == MLX_KEY_UP)
			game->input_direction &= ~UP;
		else if (event.key == MLX_KEY_A || event.key == MLX_KEY_LEFT)
			game->input_direction &= ~LEFT;
		else if (event.key == MLX_KEY_S || event.key == MLX_KEY_DOWN)
			game->input_direction &= ~DOWN;
		else if (event.key == MLX_KEY_D || event.key == MLX_KEY_RIGHT)
			game->input_direction &= ~RIGHT;
	}
}
