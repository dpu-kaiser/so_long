/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_valid_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:54:52 by dkaiser           #+#    #+#             */
/*   Updated: 2024/06/10 16:03:06 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	floodfill(char *tiles, t_ivector size, t_ivector pos);
static int	check_tiles(char *tiles, int size);

int	check_for_valid_path(t_tilemap *map)
{
	char	*tiles;

	tiles = malloc(map->grid_size.x * map->grid_size.y);
	if (!tiles)
	{
		ft_putstr_fd("Allocation error\n", 1);
		return (1);
	}
	ft_strlcpy(tiles, map->tiles, map->grid_size.x * map->grid_size.y + 1);
	floodfill(tiles, map->grid_size, map->player_start_tile);
	return (check_tiles(tiles, map->grid_size.x * map->grid_size.y));
}

static void	floodfill(char *tiles, t_ivector size, t_ivector pos)
{
	if (tiles[pos.y * size.x + pos.x] == WALL)
		return ;
	if (tiles[pos.y * size.x + pos.x] == 'X')
		return ;
	tiles[pos.y * size.x + pos.x] = 'X';
	floodfill(tiles, size, (t_ivector){pos.x - 1, pos.y});
	floodfill(tiles, size, (t_ivector){pos.x + 1, pos.y});
	floodfill(tiles, size, (t_ivector){pos.x, pos.y - 1});
	floodfill(tiles, size, (t_ivector){pos.x, pos.y + 1});
}

static int	check_tiles(char *tiles, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tiles[i] != WALL && tiles[i] != 'X')
			return (1);
		i++;
	}
	return (0);
}
