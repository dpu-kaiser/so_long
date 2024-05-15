/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:50:09 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/15 14:46:09 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "so_long.h"

static void	init_hooks(t_game *game);
static void	init_actor(t_game *game);

int	init(t_game *game)
{

	game->mlx = mlx_init(1920, 1080, "so_long", false);
	// TODO: make size and title dynamic
	game->input_direction = ZERO;
	init_hooks(game);
	init_actor(game);
	return (0);
}

static void	init_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx, loop, game);
	mlx_key_hook(game->mlx, on_key_input, game);
}

static void	init_actor(t_game *game)
{
	mlx_texture_t	*texture;
	t_actor *player;

	player = &game->player;
	texture = mlx_load_png("textures/player.png");
	player->position.x = game->map.player_start_tile.x * game->map.grid_size.x;
	player->position.y = game->map.player_start_tile.y * game->map.grid_size.y;
	player->velocity.x = 0;
	player->velocity.y = 0;
	player->size.x = 44;
	player->size.y = 44;
	player->img = mlx_texture_to_image(game->mlx, texture);
	mlx_resize_image(player->img, player->size.x, player->size.y);
	mlx_image_to_window(game->mlx, player->img, player->position.x,
						player->position.y);
}
