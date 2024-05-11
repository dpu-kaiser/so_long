/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:58:23 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/11 16:00:17 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "libft.h"
#include "so_long.h"

int draw_map(t_game *game)
{
	int x;
	int y;
	mlx_texture_t *wall_texture;
	mlx_image_t *wall_image;

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
				mlx_image_to_window(game->mlx, wall_image, x * game->map.tile_size.x, y * game->map.tile_size.y);
			y++;
		}
		x++;
	}
	return (0);
}

int	draw(t_game *game)
{
	game->player.img->instances[0].x = game->player.position.x;
	game->player.img->instances[0].y = game->player.position.y;
	return (0);
}
