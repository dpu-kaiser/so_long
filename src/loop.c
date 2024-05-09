/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:09:24 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/09 17:48:13 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "so_long.h"

int	loop(t_game *game)
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
	game->player.direction.x = ((game->input_direction & RIGHT) != 0)
		- ((game->input_direction & LEFT) != 0);
	game->player.direction.y = ((game->input_direction & DOWN) != 0)
		- ((game->input_direction & UP) != 0);
	mlx_string_put(game->mlx, game->window, 500, 500, 0x00FFFFFF,
		ft_itoa(game->player.direction.x));
	mlx_string_put(game->mlx, game->window, 550, 500, 0x00FFFFFF,
		ft_itoa(game->player.direction.y));
	return (0);
}
