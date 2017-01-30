/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:36:19 by mburson           #+#    #+#             */
/*   Updated: 2016/12/10 12:09:29 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void		init_piece(int piece)
{
	int		p;
	int		x;
	int		y;

	p = 0;
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (g_piece_types[piece][x][y])
			{
				g_p_crds_x[piece][p] = x;
				g_p_crds_y[piece][p] = y;
				p++;
			}
			y++;
		}
		x++;
	}
}

void			init_pieces_points(void)
{
	int		i;

	i = 0;
	while (i < P_TYPE_CNT)
	{
		init_piece(i);
		i++;
	}
}
