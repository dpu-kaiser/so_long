/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:47:01 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/10 15:51:50 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

static t_ivector	get_map_size_from_file(int fd);
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

static int	get_line_len(char *line)
{
	int	len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	return (len);
}
