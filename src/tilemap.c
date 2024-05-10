/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:47:01 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/10 17:26:17 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
		if (load_tiles_from_line(tilemap, l, next_line))
			return (1);
		next_line = get_next_line(fd);
		l++;
	}
	return (0);
}

static int	load_tiles_from_line(t_tilemap *tilemap, int l, char *line)
{
	int	x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		if (line[x] == EMPTY || line[x] == WALL || line[x] == COLLECTIBLE
			|| line[x] == PLAYER_START || line[x] == EXIT)
			tilemap->tiles[l * tilemap->grid_size.x + x] = line[x];
		else
			return (1);
		line++;
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
