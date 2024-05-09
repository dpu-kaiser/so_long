/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:50:09 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/09 16:13:22 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

static void	init_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx, loop, game);
	/* mlx_key_hook(game->mlx, on_key_down, game); */
	mlx_hook(game->window, 2, 0, on_key_down, game);
	mlx_hook(game->window, 3, 0, on_key_up, game);
}

int	init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 1920, 1080, "so_long");
	// TODO: make size and title dynamic
	init_hooks(game);
	return (0);
}
