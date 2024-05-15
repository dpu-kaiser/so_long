/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:58:23 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/15 17:31:11 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "libft.h"
#include "so_long.h"

int	draw(t_game *game)
{
	game->player.img->instances[0].x = game->player.position.x;
	game->player.img->instances[0].y = game->player.position.y;
	return (0);
}

void draw_exit(t_game *game)
{
	mlx_texture_t *exit_texture;
	mlx_image_t *exit_image;
	t_vector pos;

	exit_texture = mlx_load_png("textures/exit.png");
	exit_image = mlx_texture_to_image(game->mlx, exit_texture);
	mlx_resize_image(exit_image, game->map.tile_size.x, game->map.tile_size.y);
	pos = grid_to_screen_pos(game->map.exit_tile, game->map.tile_size);
	mlx_image_to_window(game->mlx, exit_image, pos.x, pos.y);
}

int	draw_walls(t_game *game)
{
	int				x;
	int				y;
	mlx_texture_t	*wall_texture;
	mlx_image_t		*wall_image;

	wall_texture = mlx_load_png("textures/wall.png");
	wall_image = mlx_texture_to_image(game->mlx, wall_texture);
	mlx_resize_image(wall_image, 48, 48);
	game->map.tile_size.x = 48;
	game->map.tile_size.y = 48;
	x = 0;
	while (x < game->map.grid_size.x)
	{
		y = 0;
		while (y < game->map.grid_size.y)
		{
			if (game->map.tiles[y * game->map.grid_size.x + x] == WALL)
				mlx_image_to_window(game->mlx, wall_image, x
					* game->map.tile_size.x, y * game->map.tile_size.y);
			y++;
		}
		x++;
	}
	return (0);
}
