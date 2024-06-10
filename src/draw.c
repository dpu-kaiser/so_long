/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:58:23 by dkaiser           #+#    #+#             */
/*   Updated: 2024/06/10 16:37:51 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "libft.h"
#include "so_long.h"

static void	draw_walls_and_collectibles(t_game *game);
static void	setup_images(t_game *game, mlx_image_t **wall_image);
static void	draw_exit(t_game *game);

void	draw(t_game *game)
{
	game->player.img->instances[0].x = game->player.position.x;
	game->player.img->instances[0].y = game->player.position.y;
}

void	draw_map(t_game *game)
{
	draw_walls_and_collectibles(game);
	draw_exit(game);
}

static void	draw_walls_and_collectibles(t_game *game)
{
	int			x;
	int			y;
	mlx_image_t	*wall_image;

	setup_images(game, &wall_image);
	x = 0;
	while (x < game->map.grid_size.x)
	{
		y = 0;
		while (y < game->map.grid_size.y)
		{
			if (game->map.tiles[y * game->map.grid_size.x + x] == WALL)
				mlx_image_to_window(game->mlx, wall_image, x
					* game->map.tile_size.x, y * game->map.tile_size.y);
			if (game->map.tiles[y * game->map.grid_size.x + x] == COLLECTIBLE)
				mlx_image_to_window(game->mlx, game->map.collectible_img, x
					* game->map.tile_size.x, y * game->map.tile_size.y);
			y++;
		}
		x++;
	}
}

static void	setup_images(t_game *game, mlx_image_t **wall_image)
{
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*collectible_texture;

	wall_texture = mlx_load_png("textures/wall.png");
	*wall_image = mlx_texture_to_image(game->mlx, wall_texture);
	collectible_texture = mlx_load_png("textures/collectible.png");
	game->map.collectible_img = mlx_texture_to_image(game->mlx,
			collectible_texture);
	mlx_resize_image(*wall_image, 48, 48);
	mlx_resize_image(game->map.collectible_img, 48, 48);
}

static void	draw_exit(t_game *game)
{
	mlx_texture_t	*exit_texture;
	mlx_image_t		*exit_image;
	t_vector		pos;

	exit_texture = mlx_load_png("textures/exit.png");
	exit_image = mlx_texture_to_image(game->mlx, exit_texture);
	mlx_resize_image(exit_image, game->map.tile_size.x, game->map.tile_size.y);
	pos = grid_to_screen_pos(game->map.exit_tile, game->map.tile_size);
	mlx_image_to_window(game->mlx, exit_image, pos.x, pos.y);
}
