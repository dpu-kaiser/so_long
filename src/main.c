/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:14:13 by dkaiser           #+#    #+#             */
/*   Updated: 2024/06/10 16:37:21 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	cleanup(t_game *game);
static int	error(char *msg);

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (error("Usage: ./so_long <map>"));
	if (load_map_from_file(&game.map, argv[1]))
		return (error("Not a valid map."));
	if (check_map(&game.map))
	{
		free(game.map.tiles);
		return (error("Not a valid map."));
	}
	init(&game);
	draw_map(&game);
	mlx_loop(game.mlx);
	cleanup(&game);
}

static void	cleanup(t_game *game)
{
	if (game->map.tiles)
		free(game->map.tiles);
	if (game->mlx)
		mlx_terminate(game->mlx);
}

static int	error(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	return (1);
}
