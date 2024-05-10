/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:50:09 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/10 12:13:33 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_hooks(t_game *game);
static void	init_player(t_player *player, int x, int y);

int	init(t_game *game)
{
	mlx_texture_t	*texture;

	game->mlx = mlx_init(1920, 1080, "so_long", false);
	// TODO: make size and title dynamic
	game->input_direction = ZERO;
	init_hooks(game);
	init_player(&game->player, 960, 540);
	// TODO: make player spawn point dynamic
	texture = mlx_load_png("textures/player.png");
	game->player.img = mlx_texture_to_image(game->mlx, texture);
	mlx_image_to_window(game->mlx, game->player.img, game->player.position.x,
		game->player.position.y);
	return (0);
}

static void	init_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx, loop, game);
	mlx_key_hook(game->mlx, on_key_input, game);
	/* mlx_hook(game->window, 2, 0, on_key_down, game); */
	/* mlx_hook(game->window, 3, 0, on_key_up, game); */
}

static void	init_player(t_player *player, int x, int y)
{
	player->position.x = x;
	player->position.y = y;
	player->velocity.x = 0;
	player->velocity.y = 0;
}
