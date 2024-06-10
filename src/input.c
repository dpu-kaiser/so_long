/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:37:40 by dkaiser           #+#    #+#             */
/*   Updated: 2024/06/10 15:58:43 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "so_long.h"

static void	on_key_press(t_game *game, mlx_key_data_t event);
static void	on_key_release(t_game *game, mlx_key_data_t event);

void	on_key_input(mlx_key_data_t event, void *params)
{
	t_game	*game;

	game = (t_game *)params;
	if (event.key == MLX_KEY_ESCAPE && event.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	else if (event.action == MLX_PRESS)
		on_key_press(game, event);
	else if (event.action == MLX_RELEASE)
		on_key_release(game, event);
}

static void	on_key_press(t_game *game, mlx_key_data_t event)
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

static void	on_key_release(t_game *game, mlx_key_data_t event)
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
