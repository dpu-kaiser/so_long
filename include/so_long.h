/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:14:02 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/09 16:13:43 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*window;
}			t_game;

int			init(t_game *game);
int			loop(t_game *game);
int	on_key_down(int key, t_game *game);
int on_key_up(int keycode, t_game *game);

#endif // SO_LONG_H
