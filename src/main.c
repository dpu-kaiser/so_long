/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:14:13 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/11 15:58:31 by dkaiser          ###   ########.fr       */
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
	draw_map(&game);
	mlx_loop(game.mlx);
}
