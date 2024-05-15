/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:48:59 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/15 15:19:54 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_map_collision_for_tile(t_collider collider, t_tilemap *map,
				t_ivector tile, enum e_tile type);

/*
 * Checks if a and b are colliding and returns the direction relative to a.
 * Example: The top left edge of a and the bottom right of b overlap.
 * In this case, check_collision() will return (UP | LEFT).
 */
int	check_collision(t_collider a, t_collider b)
{
	int	result;

	result = 0;
	if (a.position.x < b.size.x + b.position.x && a.position.x
		+ a.size.x > b.position.x && a.position.y < b.size.y + b.position.y
		&& a.position.y + a.size.y > b.position.y)
	{
		if (a.position.x < b.position.x)
			result |= RIGHT;
		if (a.position.x > b.position.x)
			result |= LEFT;
		if (a.position.y < b.position.y)
			result |= DOWN;
		if (a.position.y > b.position.y)
			result |= UP;
	}
	return (result);
}

int	check_map_collision(t_collider collider, t_tilemap *map, enum e_tile type)
{
	int			result;
	t_ivector	local_tile;
	t_ivector	check_tile;
	int			x;
	int			y;

	result = 0;
	local_tile = screen_to_grid_pos(collider.position, map->tile_size);
	x = -1;
	while (x <= 1)
	{
		y = -1;
		while (y <= 1)
		{
			check_tile.x = local_tile.x + x;
			check_tile.y = local_tile.y + y;
			result |= check_map_collision_for_tile(collider, map, check_tile, type);
			y++;
		}
		x++;
	}
	return (result);
}

static int	check_map_collision_for_tile(t_collider collider, t_tilemap *map,
		t_ivector tile, enum e_tile type)
{
	t_collider	tile_collider;

	if (get_tile(map, tile.x, tile.y) == type)
	{
		tile_collider.position = grid_to_screen_pos(tile, map->tile_size);
		tile_collider.size.x = map->tile_size.x;
		tile_collider.size.y = map->tile_size.y;
		return (check_collision(collider, tile_collider));
	}
	return (0);
}

void	move_and_slide(t_actor *actor, t_tilemap *map, double delta_time)
{
	t_collider	c;

	c.size = actor->size;
	c.position.x = actor->position.x + (actor->velocity.x * delta_time);
	c.position.y = actor->position.y;
	if ((check_map_collision(c, map, WALL) & (RIGHT | LEFT)) == 0)
		actor->position.x = c.position.x;
	else
		actor->velocity.x = 0;
	c.position.x = actor->position.x;
	c.position.y = actor->position.y + (actor->velocity.y * delta_time);
	if ((check_map_collision(c, map, WALL) & (UP | DOWN)) == 0)
		actor->position.y = c.position.y;
	else
		actor->velocity.y = 0;
}

int	is_on_floor(t_collider collider, t_tilemap *map)
{
	collider.position.y += 5;
	if (check_map_collision(collider, map, WALL))
		return (1);
	return (0);
}
