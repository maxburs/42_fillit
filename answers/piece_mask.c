/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:20:32 by mburson           #+#    #+#             */
/*   Updated: 2016/12/10 12:09:17 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** gets piece part and returns no part when out of bounds
*/

_Bool	get_pp(int piece, int x, int y)
{
	if (x > 3 || x < 0 || y > 3 || y < 0)
		return (0);
	return (g_piece_types[piece][x][y]);
}

char	map_mask(char **map, int size, int x, int y)
{
	if (x < size && y < size)
		return (map[y][x]);
	return ('Z');
}
