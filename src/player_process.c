/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:40:05 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/20 20:29:07 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "so_long.h"

static t_vector	get_direction_from_input(t_game *game);
static void		handle_collectible_collision(t_actor *player, t_tilemap *map);
static void		collect_collectible(t_ivector pos, t_tilemap *map);
static void		handle_exit_collision(t_actor *player, t_tilemap *map);

void	player_process(t_game *game)
{
	t_actor	*player;

	player = &game->player;
	player->direction = get_direction_from_input(game);
	player->velocity.x = player->direction.x * PLAYER_MOVE_SPEED;
	player->velocity.y += 50;
	if (player->direction.y == -1 && is_on_floor((t_collider){player->position,
			player->size}, &game->map))
		player->velocity.y = -1000;
	handle_collectible_collision(player, &game->map);
	handle_exit_collision(player, &game->map);
	move_and_slide(player, &game->map, game->mlx->delta_time);
}

static void	handle_collectible_collision(t_actor *player, t_tilemap *map)
{
	t_collider	player_collider;
	int			collision;
	t_ivector	player_tile;

	player_collider = (t_collider){player->position, player->size};
	player_tile = screen_to_grid_pos(player->position, map->tile_size);
	collision = check_map_collision(player_collider, map, COLLECTIBLE);
	if (collision & UP)
	{
		if (collision & LEFT)
			collect_collectible(player_tile, map);
		if (collision & RIGHT)
			collect_collectible((t_ivector){player_tile.x + 1, player_tile.y},
				map);
	}
	if (collision & DOWN)
	{
		if (collision & LEFT)
			collect_collectible((t_ivector){player_tile.x, player_tile.y + 1},
				map);
		if (collision & RIGHT)
			collect_collectible((t_ivector){player_tile.x + 1, player_tile.y
				+ 1}, map);
	}
}

static void	collect_collectible(t_ivector pos, t_tilemap *map)
{
	size_t i;
	t_vector collectible_pos;
	t_ivector collectible_tile;

	ft_printf("Collected a collectile.\n");
	set_tile(map, pos.x, pos.y, EMPTY);
	i = 0;
	while (i < map->collectible_img->count)
	{
		collectible_pos.x = map->collectible_img->instances[i].x;
		collectible_pos.y = map->collectible_img->instances[i].y;
		collectible_tile = screen_to_grid_pos(collectible_pos, map->tile_size);
		if (pos.x == collectible_tile.x && pos.y == collectible_tile.y)
		{
			map->collectible_img->instances[i].enabled = 0;
			break ;
		}
		i++;
	}
}

static void	handle_exit_collision(t_actor *player, t_tilemap *map)
{
	t_collider	player_collider;
	size_t i;

	player_collider = (t_collider){player->position, player->size};
	if (check_map_collision(player_collider, map, EXIT))
	{
		i = 0;
		while (i < map->collectible_img->count)
		{
			if (map->collectible_img->instances[i].enabled)
				return ;
			i++;
		}
		exit(0);
	}
}

static t_vector	get_direction_from_input(t_game *game)
{
	t_vector	result;

	result.x = ((game->input_direction & RIGHT) != 0)
		- ((game->input_direction & LEFT) != 0);
	result.y = ((game->input_direction & DOWN) != 0)
		- ((game->input_direction & UP) != 0);
	return (result);
}
