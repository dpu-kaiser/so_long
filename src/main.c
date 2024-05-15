/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:14:13 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/15 17:31:46 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (1);
	if (load_map_from_file(&game.map, argv[1]))
		return (1);
	init(&game);
	draw_walls(&game);
	draw_exit(&game);
	mlx_loop(game.mlx);
}
