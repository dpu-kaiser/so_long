/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:47:01 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/11 16:19:50 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "so_long.h"

static t_ivector	get_map_size_from_file(int fd);
static int			load_tiles_from_file(t_tilemap *tilemap, int fd);
static int			load_tiles_from_line(t_tilemap *tilemap, int l, char *line);
static int			get_line_len(char *line);

int	load_map_from_file(t_tilemap *tilemap, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	tilemap->grid_size = get_map_size_from_file(fd);
	close(fd);
	if (tilemap->grid_size.x < 0 || tilemap->grid_size.y < 0)
		return (1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	if (load_tiles_from_file(tilemap, fd))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

static t_ivector	get_map_size_from_file(int fd)
{
	t_ivector	result;
	char		*next_line;

	result.x = 0;
	result.y = 0;
	next_line = get_next_line(fd);
	while (next_line)
	{
		if (!result.x)
			result.x = get_line_len(next_line);
		else if (result.x != get_line_len(next_line))
		{
			free(next_line);
			result.x = -1;
			result.y = -1;
			return (result);
		}
		result.y++;
		free(next_line);
		next_line = get_next_line(fd);
	}
	return (result);
}

static int	load_tiles_from_file(t_tilemap *tilemap, int fd)
{
	int		l;
	char	*next_line;

	tilemap->tiles = malloc(tilemap->grid_size.x * tilemap->grid_size.y
			* sizeof(char));
	if (!tilemap->tiles)
		return (1);
	l = 0;
	next_line = get_next_line(fd);
	while (next_line)
	{
		if (load_tiles_from_line(tilemap, l++, next_line))
			return (1);
		next_line = get_next_line(fd);
	}
	return (0);
}

static int	load_tiles_from_line(t_tilemap *tilemap, int l, char *line)
{
	t_ivector	pos;
	static int	found_player_start;
	static int	found_exit;

	pos.x = 0;
	pos.y = l;
	while (line[pos.x] && line[pos.x] != '\n')
	{
		if (line[pos.x] != '0' && line[pos.x] != '1' && line[pos.x] != 'C'
			&& line[pos.x] != 'P' && line[pos.x] != 'E')
			return (1);
		if (line[pos.x] == PLAYER_START && !found_player_start)
		{
			tilemap->player_start_tile = pos;
			found_player_start = 1;
		}
		else if (line[pos.x] == EXIT && !found_exit)
		{
			tilemap->exit_tile = pos;
			found_exit = 1;
		}
		tilemap->tiles[l * tilemap->grid_size.x + pos.x] = line[pos.x];
		pos.x++;
	}
	return (0);
}

static int	get_line_len(char *line)
{
	int	len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	return (len);
}
