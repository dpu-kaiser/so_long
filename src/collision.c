/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:48:59 by dkaiser           #+#    #+#             */
/*   Updated: 2024/05/14 12:26:02 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collision(t_vector a_pos, t_vector a_size, t_vector b_pos,
		t_vector b_size)
{
    int result;

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

