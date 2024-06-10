/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:50:09 by dkaiser           #+#    #+#             */
/*   Updated: 2024/06/10 15:55:28 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "so_long.h"

static void	init_hooks(t_game *game);
static void	init_player(t_game *game);

int	init(t_game *game)
{
	game->input_direction = ZERO;
	game->map.tile_size = (t_ivector){48, 48};
	game->mlx = mlx_init(game->map.grid_size.x * game->map.tile_size.x,
			game->map.grid_size.y * game->map.tile_size.y, "so_long", false);
	init_hooks(game);
	init_player(game);
	return (0);
}

static void	init_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx, loop, game);
	mlx_key_hook(game->mlx, on_key_input, game);
}

static void	init_player(t_game *game)
{
	mlx_texture_t	*texture;
	t_actor			*player;

	player = &game->player;
	texture = mlx_load_png("textures/player.png");
	player->position = grid_to_screen_pos(game->map.player_start_tile,
			game->map.tile_size);
	player->velocity = (t_vector){0, 0};
	player->size = (t_ivector){44, 44};
	player->steps = 0;
	ft_printf("Steps: %d\n", game->player.steps);
	player->img = mlx_texture_to_image(game->mlx, texture);
	mlx_resize_image(player->img, player->size.x, player->size.y);
	mlx_image_to_window(game->mlx, player->img, player->position.x,
		player->position.y);
}
