/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:48:59 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/14 14:59:13 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_wall_collision_with_cell(t_vector a_pos, t_ivector a_size,
				t_tilemap *map, t_ivector tile);

/*
 * Checks if a and b are colliding and returns the direction relative to a.
 * Example: The top left edge of a and the bottom right of b overlap.
 * In this case, check_collision() will return (UP | LEFT).
 */
int	check_collision(t_vector a_pos, t_ivector a_size, t_vector b_pos,
		t_ivector b_size)
{
	int	result;

	result = 0;
	if (a_pos.x < b_size.x + b_pos.x && a_pos.x + a_size.x > b_pos.x
		&& a_pos.y < b_size.y + b_pos.y && a_pos.y + a_size.y > b_pos.y)
	{
		if (a_pos.x < b_pos.x)
			result |= RIGHT;
		if (a_pos.x > b_pos.x)
			result |= LEFT;
		if (a_pos.y < b_pos.y)
			result |= DOWN;
		if (a_pos.y > b_pos.y)
			result |= UP;
	}
	return (result);
}

int	check_wall_collision(t_vector a_pos, t_ivector a_size, t_tilemap *map)
{
	int			result;
	t_ivector	a_tile;
	t_ivector	check_tile;
	int			x;
	int			y;

    result = 0;
	a_tile = screen_to_grid_pos(a_pos, map->tile_size);
	x = -1;
	while (x <= 1)
	{
		y = -1;
		while (y <= 1)
		{
            check_tile.x = a_tile.x + x;
            check_tile.y = a_tile.y + y;
			result |= check_wall_collision_with_cell(a_pos, a_size, map,
					check_tile);
			y++;
		}
		x++;
	}
	return (result);
}

static int	check_wall_collision_with_cell(t_vector a_pos, t_ivector a_size,
		t_tilemap *map, t_ivector tile)
{
	t_vector	wall_pos;
	t_ivector	wall_size;

	if (get_tile(map, tile.x, tile.y) == WALL)
	{
		wall_pos = grid_to_screen_pos(tile, map->tile_size);
		wall_size.x = map->tile_size.x;
		wall_size.y = map->tile_size.y;
		return (check_collision(a_pos, a_size, wall_pos, wall_size));
	}
	return (0);
}
