/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:58:23 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/10 10:53:52 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	if (game->input_direction & UP)
		mlx_string_put(game->mlx, game->window, 150, 100, 0x00FFFFFF, "^");
	if (game->input_direction & DOWN)
		mlx_string_put(game->mlx, game->window, 150, 200, 0x00FFFFFF, "v");
	if (game->input_direction & LEFT)
		mlx_string_put(game->mlx, game->window, 100, 150, 0x00FFFFFF, "<");
	if (game->input_direction & RIGHT)
		mlx_string_put(game->mlx, game->window, 200, 150, 0x00FFFFFF, ">");
	mlx_string_put(game->mlx, game->window, 500, 500, 0x00FFFFFF,
		ft_itoa(game->player.direction.x));
	mlx_string_put(game->mlx, game->window, 550, 500, 0x00FFFFFF,
		ft_itoa(game->player.direction.y));
	mlx_put_image_to_window(game->mlx, game->window, game->player.img,
		game->player.position.x, game->player.position.y);
	return (0);
}
