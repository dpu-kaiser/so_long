/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:19:34 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/15 15:04:31 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector	grid_to_screen_pos(t_ivector grid_pos, t_ivector tile_size)
{
	t_vector	screen_pos;

	screen_pos.x = grid_pos.x * tile_size.x;
	screen_pos.y = grid_pos.y * tile_size.y;
	return (screen_pos);
}

t_ivector	screen_to_grid_pos(t_vector screen_pos, t_ivector tile_size)
{
	t_ivector	grid_pos;

	grid_pos.x = screen_pos.x / tile_size.x;
	grid_pos.y = screen_pos.y / tile_size.y;
	return (grid_pos);
}

enum e_tile	get_tile(t_tilemap *map, int x, int y)
{
	return (map->tiles[y * map->grid_size.x + x]);
}
