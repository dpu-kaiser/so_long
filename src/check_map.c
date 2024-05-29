/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:23:01 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/29 15:58:10 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_borders(t_tilemap *map);
static int	check_exactly_one(t_tilemap *map, char tile);
static int	check_collectibles(t_tilemap *map);

int	check_map(t_tilemap *map)
{
	if (check_borders(map))
		return (1);
	if (check_exactly_one(map, PLAYER_START))
		return (1);
	if (check_exactly_one(map, EXIT))
		return (1);
	if (check_collectibles(map))
		return (1);
	if (check_for_valid_path(map))
		return (1);
	return (0);
}

static int	check_borders(t_tilemap *map)
{
	int	i;

	i = 0;
	while (i < map->grid_size.x)
	{
		if (get_tile(map, i, 0) != WALL || get_tile(map, i, map->grid_size.y
				- 1) != WALL)
			return (1);
		i++;
	}
	i = 0;
	while (i < map->grid_size.y)
	{
		if (get_tile(map, 0, i) != WALL || get_tile(map, map->grid_size.x - 1,
				i) != WALL)
			return (1);
		i++;
	}
	return (0);
}

static int	check_exactly_one(t_tilemap *map, char tile)
{
	int	i;
	int	found;

	found = 0;
	i = map->grid_size.x * map->grid_size.y - 1;
	while (i >= 0)
	{
		if (map->tiles[i] == tile)
			found++;
		i--;
	}
	if (found != 1)
		return (1);
	return (0);
}

static int	check_collectibles(t_tilemap *map)
{
	int	i;

	i = map->grid_size.x * map->grid_size.y - 1;
	while (i >= 0)
	{
		if (map->tiles[i] == COLLECTIBLE)
			return (0);
		i--;
	}
	ft_printf("\nFound no collectibles\n");
	return (1);
}
